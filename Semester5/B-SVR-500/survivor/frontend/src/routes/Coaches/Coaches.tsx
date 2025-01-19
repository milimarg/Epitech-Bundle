import React from 'react';
import Page from '../../components/Page/Page';
import TableComponent from '../../components/Table/Table';
import Button from '../../components/Button/Button';
import BackendRequester from '../../utils/backendRequester';
import CircularProgress from '@mui/material/CircularProgress';
import './Coaches.css';
import {Customer, Employee} from "../../utils/types";
import Modal from "../../components/Modal/Modal";
import Card from "../../components/Card/Card";
import NameAvatar from "../../components/NameAvatar/NameAvatar";

type Props = {};

type State = {
  tableData: {
    coachName: string;
    Coach: JSX.Element;
    Email: string;
    Phone: string;
    'Number of customers': number;
    Actions: JSX.Element;
  }[],
  status: "loading" | "success" | "error",
  message?: string,
  selectedCoach: Employee | null,
  modalOpen: boolean,
  customers: Customer[],
  selected: number[]
};

export default class Coaches extends React.Component<Props, State> {
  state: State = {
    tableData: [],
    status: "loading",
    selectedCoach: null,
    modalOpen: false,
    customers: [],
    selected: []
  };

  openModal(employee: Employee, customers: Customer[]) {
    this.setState({
      modalOpen: true,
      selectedCoach: employee,
      customers: customers,
      selected: employee.assigned_customers
    });
  }

  closeModal = () => {
    this.setState({ modalOpen: false, selectedCoach: null, selected: [] });
  };

  selectUser =(userId: number) => {
    const selected: number[] = this.state.selected;
    const index = selected.indexOf(userId);

    if (index === -1)
      selected.push(userId);
    else
      selected.splice(index, 1);
    this.setState({ selected: selected });
  }

  saveRegisteredCustomers = () => {
    const selected = this.state.selected;

    if (!this.state?.selectedCoach)
      return;
    BackendRequester.updateAssignedCustomers(this.state.selectedCoach.id, selected).then();
    this.setState({ selected: [] });
    this.closeModal();
  }

  async componentDidMount() {
    try {
      const coaches = await BackendRequester.fetchCoachesData();
      const customers = await BackendRequester.fetchCustomersData();

      if (BackendRequester.isFetchError(customers)) {
        this.setState({ status: "error", message: customers.type + " " + customers.message });
        return;
      }
      if (Array.isArray(coaches) && customers) {
        const tableData = coaches.sort((a, b) => a.id - b.id).map((coach) => {
          return {
            coachName: coach.name + " " + coach.surname,
            Coach: (
              <NameAvatar
                src={!coach.image ? undefined : `data:image/png;base64, ${coach.image}`}
                alt={"customer face"}
                name={coach.name}
                surname={coach.surname}
                size={"medium"}
              />
            ),
            Email: coach.email,
            Phone: "None",
            'Number of customers': coach.assigned_customers.length,
            Actions: (
              <Button
                text="..."
                onClick={() => this.openModal(coach, customers)}
                size='small'
                color='secondary'
              />
            ),
          };
        });
        this.setState({ tableData, status: "success" });
      } else {
        this.setState({ status: "error", message: "Error fetching coaches/customers data: Invalid data" });
      }
    } catch (error) {
      this.setState({ status: "error", message: "Error fetching coaches/customers data:" + error });
    }
  }

  render() {
    const columnContent = ['Coach', 'Email', 'Phone', 'Number of customers', 'Actions'];
    const { status, message, tableData, modalOpen, customers } = this.state;
    const placeholderImage = "https://via.placeholder.com/300x300.png?text=No+image";

    let renderElement: React.ReactNode;

    switch (status) {
      case "loading":
        renderElement =
          <div className={"loading-screen"}>
            <CircularProgress color="inherit" />
          </div>;
        break;
      case "error":
        renderElement =
        <div className={"error-message"}>
            <p>{message}</p>
        </div>;
        break;
      case "success":
        renderElement =
        <div className='table-container-wrapper'>
          <div className="table-container">
            <TableComponent
              columns={columnContent}
              data={tableData}
              showCheckboxes
              searchValues={{
                placeholder: "Enter name",
                suggestions: tableData.map((data) => data.coachName ),
                searchDataKeys: ["coachName", "Email", "Phone"]
              }}
            />
          </div>
          <Modal
            open={modalOpen}
            onClose={this.closeModal}
            title={`Assign customers`}
            fullWidth
            fullHeight
            actions={
              <button onClick={() => this.saveRegisteredCustomers()}>Apply</button>
            }
          >

            <div className="customer-photos">
              {customers.map((customer: Customer, index) => (
                <div
                  key={index}
                  onClick={() => this.selectUser(customer.id)}
                  className={this.state.selected.includes(customer.id) ? "selected-customer" : ""}
                >
                  <Card
                    key={index}
                    title={customer.name + " " + customer.surname}
                    content={
                      <img
                        className={"coach-menu-customer-photo"}
                        src={customer.image === null ? placeholderImage : 'data:image/png;base64, ' + customer.image}
                        alt="Customer Face"
                      />
                    }
                  />
                </div>
              ))}
            </div>
          </Modal>
        </div>
        break;
    }

    return (
      <Page pageTitle="Coaches List">
        {renderElement}
      </Page>
    );
  }
}
