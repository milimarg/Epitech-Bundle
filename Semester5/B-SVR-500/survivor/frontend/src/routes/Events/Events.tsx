import React, { createRef } from "react";
import Page from '../../components/Page/Page';
import { Event, Comment, Customer, TokenValue, Employee } from "../../utils/types";
import BackendRequester from "../../utils/backendRequester";
import Card from "../../components/Card/Card";
import Modal from '../../components/Modal/Modal';
import { icon, Map } from "leaflet";
import { MapContainer, TileLayer, Marker, Popup } from "react-leaflet";
import CircularProgress from '@mui/material/CircularProgress';
import Calendar from "../../components/Calendar/Calendar";
import { DateClickArg } from "@fullcalendar/interaction";
import { EventClickArg } from "@fullcalendar/core";
import CommentComponent from "../../components/CommentComponent/CommentComponent";
import Button from "../../components/Button/Button";
import { jwtDecode } from "jwt-decode";
import "./Events.css";
import 'leaflet/dist/leaflet.css';
import NameAvatarComponent from "../../components/NameAvatar/NameAvatar";

type Props = {};

type CommentWithCustomer = Comment & {
  customer?: Customer;
};

type State = {
  events: Event[];
  selectedEvent: Event | null;
  modalOpen: boolean;
  role: 'CUSTOMER' | 'COACH' | 'ADMIN';
  comments: CommentWithCustomer[];
  subscribers: Customer[];
  isSubscribed: boolean;
  eventLimit: number | null;
  status: "loading" | "success" | "error";
  message?: string;
  userInfo?: Customer | Employee;
};

const customIcon = icon({
  iconUrl: 'https://freesvg.org/storage/img/thumb/map-pin.png',
  iconSize: [32, 32],
  iconAnchor: [16, 32],
  popupAnchor: [0, -32]
});

export default class Events extends React.Component<Props, State> {
  mapRef = createRef<Map>();

  state: State = {
    events: [],
    selectedEvent: null,
    modalOpen: false,
    role: 'CUSTOMER',
    comments: [],
    subscribers: [],
    isSubscribed: false,
    status: "loading",
    eventLimit: null,
  };

  async componentDidMount() {
    const token = localStorage.getItem('authToken');
    let decoded: TokenValue | undefined = undefined;
    if (token)
      decoded = jwtDecode(token) as TokenValue;
    if (decoded) {
      this.setState({ role: decoded.permission });
      switch (decoded.permission) {
        case "COACH":
          break;
        case "ADMIN":
          break;
        case "CUSTOMER":
          const customer = await BackendRequester.fetchCustomerInfoMe();
          if (BackendRequester.isFetchError(customer))
            this.setState({ status: "error", message: `${customer.type} ${customer.message}` });
          else
            this.setState({ userInfo: customer })
          break;
      }
    }

    try {
      const eventsData = await BackendRequester.fetchEvents();
      if (BackendRequester.isFetchError(eventsData)) {
        this.setState({ status: "error", message: `${eventsData.type} ${eventsData.message}` });
        return;
      }
      if (Array.isArray(eventsData)) {
        const events: Event[] = eventsData.map(event => ({
          ...event,
          // status: 'upcoming', // ! debug value
        }));
        this.setState({ events, status: "success" });
      } else {
        this.setState({ status: "error", message: "Error fetching events data: Invalid response" });
      }
    } catch (error) {
      this.setState({ status: "error", message: `Error fetching events data: ${error}` });
    }

    setTimeout(() => {
      this.invalidateMapSize();
    }, 300);
  }

  componentDidUpdate(prevProps: Props, prevState: State) {
    if (prevState.modalOpen !== this.state.modalOpen || prevState.events !== this.state.events)
      this.invalidateMapSize();
  }

  invalidateMapSize = () => {
    this.mapRef.current?.invalidateSize();
  };

  openModal = async (event: Event) => {
    try {
      const commentsData = await BackendRequester.fetchEventComments(event.id);
      const subscribersData = await BackendRequester.fetchEventSubscribers(event.id);
      if (BackendRequester.isFetchError(commentsData) || BackendRequester.isFetchError(subscribersData)) {
        this.setState({ status: "error", message: `Error fetching event details` });
        return;
      }

      const uniqueCustomerIds = Array.from(new Set(commentsData.map(comment => comment.customer_id)));

      const customersMap: { [key: number]: Customer } = {};
      for (const customerId of uniqueCustomerIds) {
        const customer = await BackendRequester.fetchCustomerById(customerId);
        if (!BackendRequester.isFetchError(customer))
          customersMap[customerId] = customer;
      }

      const commentsWithCustomer: CommentWithCustomer[] = commentsData.map(comment => ({
        ...comment,
        customer: customersMap[comment.customer_id]
      }));

      this.setState({
        selectedEvent: event,
        modalOpen: true,
        comments: commentsWithCustomer,
        subscribers: subscribersData,
        eventLimit: event.max_participants || null,
        isSubscribed: this.state.role === "CUSTOMER" && subscribersData.some((customer) => customer.id === this.state.userInfo?.id)
      });
    } catch (error) {
      this.setState({ status: "error", message: `Error fetching event details: ${error}` });
    }
  };

  closeModal = () => {
    this.setState({ modalOpen: false });
  };

  handleUnregister = async (customerId: number) => {
    const { selectedEvent } = this.state;

    if (selectedEvent) {
      try {
        await BackendRequester.unsubscribedFromEvent(selectedEvent.id, customerId);
        this.setState({ modalOpen: false });
        this.refreshEventData(selectedEvent.id);
      } catch (error) {
        this.setState({ status: "error", message: `Error unregistering from the event: ${error}` });
      }
    }
  };

  toggleSubscription = async () => {
    const { selectedEvent, isSubscribed, role, userInfo } = this.state;

    if (role !== "CUSTOMER" || !userInfo)
      return;

    const customerId = userInfo.id;

    if (selectedEvent) {
      try {
        if (isSubscribed)
          await BackendRequester.unsubscribedFromEvent(selectedEvent.id, customerId);
        else
          await BackendRequester.subscribedToEvent(selectedEvent.id, customerId);
        this.setState(prevState => ({ isSubscribed: !prevState.isSubscribed }));
        this.refreshEventData(selectedEvent.id);
      } catch (error) {
        this.setState({ status: "error", message: `Error toggling subscription to the event: ${error}` });
      }
    }
  };

  handlePostComment = async (comment: string) => {
    if (!comment.length)
      return;

    const { selectedEvent, role, userInfo } = this.state;

    if (role !== "CUSTOMER" || !userInfo)
      return;

    const customerId = userInfo.id;

    if (selectedEvent) {
      try {
        await BackendRequester.addCommentToEvent(customerId, selectedEvent.id, comment);
        this.setState(prevState => ({
          comments: [
            ...prevState.comments,
            {
              id: Date.now(),
              customer_id: customerId,
              event_id: selectedEvent.id,
              message: comment,
              customer: prevState.userInfo as Customer
            }
          ]
        }));
      } catch (error) {
        this.setState({ status: "error", message: `Error posting comment: ${error}` });
      }
    }
  };

  handleRemoveComment = async (commentId: number) => {
    try {
      await BackendRequester.removeCommentFromEvent(commentId);
      this.setState(prevState => ({
        comments: prevState.comments.filter(comment => comment.id !== commentId)
      }));
    } catch (error) {
      this.setState({ status: "error", message: `Error removing comment: ${error}` });
    }
  };

  handleUpdateLimit = async (eventLimit: number) => {
    const { selectedEvent } = this.state;

    if (selectedEvent) {
      try {
        await BackendRequester.setLimitEvent(selectedEvent.id, eventLimit);
        this.setState({ eventLimit });
        this.refreshEventData(selectedEvent.id);
      } catch (error) {
        this.setState({ status: "error", message: `Error updating event limit: ${error}` });
      }
    }
  };

  refreshEventData = async (eventId: number) => {
    try {
      const commentsData = await BackendRequester.fetchEventComments(eventId);
      const subscribersData = await BackendRequester.fetchEventSubscribers(eventId);
      if (BackendRequester.isFetchError(commentsData) || BackendRequester.isFetchError(subscribersData)) {
        this.setState({ status: "error", message: `Error refreshing event data` });
        return;
      }

      const uniqueCustomerIds = Array.from(new Set(commentsData.map(comment => comment.customer_id)));

      const customersMap: { [key: number]: Customer } = {};
      for (const customerId of uniqueCustomerIds) {
        const customer = await BackendRequester.fetchCustomerById(customerId);
        if (!BackendRequester.isFetchError(customer))
          customersMap[customerId] = customer;
      }

      const commentsWithCustomer: CommentWithCustomer[] = commentsData.map(comment => ({
        ...comment,
        customer: customersMap[comment.customer_id]
      }));

      this.setState({
        comments: commentsWithCustomer,
        subscribers: subscribersData
      });
    } catch (error) {
      this.setState({ status: "error", message: `Error refreshing event data: ${error}` });
    }
  };

  clickOnEmptyTile = (arg: DateClickArg) => {
  };

  clickOnEvent = (arg: EventClickArg) => {
    const eventId = +arg.event.id;
    const event = this.state.events.find(event => event.id === eventId);
    if (event)
      this.openModal(event);
  };

  render() {
    const { events, selectedEvent, modalOpen, role, comments, subscribers, status, message } = this.state;

    const tempEvents = events.map(event => ({
      title: event.name,
      date: event.date,
      id: event.id
    }));

    let renderElement: React.ReactNode;

    switch (status) {
      case "loading":
        renderElement = (
          <div className="loading-screen">
            <CircularProgress color="inherit" />
          </div>
        );
        break;
      case "error":
        renderElement = (
          <div className="error-message">
            <p>{message}</p>
          </div>
        );
        break;
      case "success":
        renderElement = (
          <div className="events">
            <Card
              title=""
              width="95%"
              content={
                <Calendar
                  events={tempEvents}
                  clickOnEmptyTile={this.clickOnEmptyTile}
                  clickOnEvent={this.clickOnEvent}
                />
              }
            />

            <div className="map-block-card-wrapper">
              <Card
                title=""
                width="95%"
                content={
                  <MapContainer
                    center={[46.603354, 1.888334]}
                    zoom={6}
                    scrollWheelZoom={false}
                    style={{ height: "100vh", width: "100%" }}
                    ref={this.mapRef}
                  >
                    <TileLayer
                      url="https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png"
                      attribution='&copy; <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a> contributors'
                    />
                    {events.map(event => (
                      <Marker
                        key={event.id}
                        position={[+event.location_x, +event.location_y]}
                        icon={customIcon}
                      >
                        <Popup>{event.name}</Popup>
                      </Marker>
                    ))}
                  </MapContainer>
                }
              />
            </div>

            {modalOpen && selectedEvent && (
              <Modal
                open={modalOpen}
                onClose={this.closeModal}
                title={selectedEvent.name}
              >
                <div>
                  <p><strong>Date:</strong> {selectedEvent.date}</p>
                  <p><strong>Location:</strong> {selectedEvent.location_name}</p>
                  <p><strong>Status:</strong> {selectedEvent.status}</p>
                  <p><strong>Participants:</strong> {selectedEvent.id_subscribed.length}/{selectedEvent.max_participants}</p>
                  {role !== 'CUSTOMER' && selectedEvent.status === 'upcoming' && (
                    <>
                      <h3>Subscribers:</h3>
                      <ul>
                        {subscribers.map(subscriber => (
                          <li key={subscriber.id}>
                            <NameAvatarComponent
                              name={subscriber.name}
                              surname={subscriber.surname}
                              src={subscriber.image ? ('data:image/png;base64, ' + subscriber.image) : ''}
                              alt=''
                            />
                            <button onClick={() => this.handleUnregister(subscriber.id)}>
                              Unsubscribe
                            </button>
                          </li>
                        ))}
                      </ul>
                    </>
                  )}
                </div>

                {role === 'CUSTOMER' && selectedEvent.status === 'passed' && (
                  <div className="comment-form">
                    <input
                      type="text"
                      placeholder="Write your comment"
                      onKeyDown={(e) => {
                        if (e.key === 'Enter') {
                          this.handlePostComment((e.target as HTMLInputElement).value);
                          (e.target as HTMLInputElement).value = '';
                        }
                      }}
                    />
                  </div>
                )}

                {selectedEvent.status !== "upcoming" && (
                  <>
                    <h4>Comments:</h4>
                    <div>
                      {comments.length ? comments.map((comment, index) => (
                        <CommentComponent
                          key={index}
                          comment={comment.message}
                          canRemove={role !== 'CUSTOMER'}
                          onRemove={() => this.handleRemoveComment(comment.id)}
                          name={comment.customer?.name ?? ''}
                          surname={comment.customer?.surname ?? ''}
                          image={comment.customer?.image ? ('data:image/png;base64, ' + comment.customer.image) : ''}
                        />
                      )) : <p>No comments yet.</p>}
                    </div>
                  </>
                )}

                {role === 'CUSTOMER' && selectedEvent.status === 'upcoming' && (
                  <Button
                    text={this.state.isSubscribed ? "Unregister" : "Register"}
                    onClick={this.toggleSubscription}
                    color="secondary"
                  />
                )}
              </Modal>
            )}
          </div>
        );
        break;
    }

    return <Page>{renderElement}</Page>;
  }
}
