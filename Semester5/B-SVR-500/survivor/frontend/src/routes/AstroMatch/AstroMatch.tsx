import React from 'react';
import Page from '../../components/Page/Page';
import Card from '../../components/Card/Card';
import CircularProgress from '@mui/material/CircularProgress';
import { ZodiacSign } from '../../utils/types';
import { compatibilityMatrix } from './zodiacSignsValues';
import BackendRequester from '../../utils/backendRequester';
import Modal from '../../components/Modal/Modal';
import './AstroMatch.css'

import { ReactComponent as Aquarius } from './zodiac-signs/aquarius.svg';
import { ReactComponent as Aries } from './zodiac-signs/aries.svg';
import { ReactComponent as Cancer } from './zodiac-signs/cancer.svg';
import { ReactComponent as Capricorn } from './zodiac-signs/capricorn.svg';
import { ReactComponent as Gemini } from './zodiac-signs/gemini.svg';
import { ReactComponent as Leo } from './zodiac-signs/leo.svg';
import { ReactComponent as Libra } from './zodiac-signs/libra.svg';
import { ReactComponent as Pisces } from './zodiac-signs/pisces.svg';
import { ReactComponent as Sagittarius } from './zodiac-signs/saggitarius.svg';
import { ReactComponent as Scorpio } from './zodiac-signs/scorpio.svg';
import { ReactComponent as Taurus } from './zodiac-signs/taurus.svg';
import { ReactComponent as Virgo } from './zodiac-signs/virgo.svg';
import Button from '../../components/Button/Button';

type Customer = {
  id: number,
  name: string,
  surname: string,
  fullName: string,
  image: string,
  astrologicalSign: ZodiacSign
};

type Props = {};

type State = {
  customers: Customer[],
  selectedCustomer1: Customer | null,
  selectedCustomer2: Customer | null,
  matchPercentage: number,
  status: "loading" | "success" | "error",
  message?: string,
  leftModalOpen: boolean,
  rightModalOpen: boolean,
  selected?: number,
};

type ZodiacSvg = React.FunctionComponent<React.SVGProps<SVGSVGElement> & { title?: string; }>;

const zodiacIcons: { [key: string]: ZodiacSvg } = {
  Aries,
  Taurus,
  Gemini,
  Cancer,
  Leo,
  Virgo,
  Libra,
  Scorpio,
  Sagittarius,
  Capricorn,
  Aquarius,
  Pisces,
};

export default class AstroMatch extends React.Component<Props, State> {
  state: State = {
    customers: [],
    selectedCustomer1: null,
    selectedCustomer2: null,
    matchPercentage: 0,
    status: "loading",
    leftModalOpen: false,
    rightModalOpen: false,
  };

  async componentDidMount() {
    try {
      const customers = await BackendRequester.fetchCustomersData();

      if (BackendRequester.isFetchError(customers)) {
        this.setState({ status: "error", message: customers.type + " " + customers.message });
        return;
      }
      if (Array.isArray(customers)) {
        const newCustomers: Customer[] = customers.map((tempCust) => {
          return ({
            id: tempCust.id,
            name: tempCust.name,
            surname: tempCust.surname,
            fullName: tempCust.surname + " " + tempCust.name,
            image: tempCust.image ?? '',
            astrologicalSign: tempCust.astrological_sign,
          });
        })
        this.setState({ customers: newCustomers, status: "success" });
      } else
        this.setState({ status: "error", message: "Error fetching customers data: Invalid data" });
    } catch (error) {
      this.setState({ status: "error", message: "Error fetching customers data:" + error });
    }
  }

  handleCustomerChange = (which: 'first' | 'second') => () => {
    const selectedCustomer = this.state.customers.find(client => client.id === this.state.selected) ?? null;
    if (which === 'first') {
      this.setState({ selectedCustomer1: selectedCustomer }, this.calculateMatch);
      this.closeLeftModal();
    } else {
      this.setState({ selectedCustomer2: selectedCustomer }, this.calculateMatch);
      this.closeRightModal();
    }
  };

  calculateMatch = () => {
    const { selectedCustomer1, selectedCustomer2 } = this.state;
    if (selectedCustomer1 && selectedCustomer2) {
      const sign1 = selectedCustomer1.astrologicalSign;
      const sign2 = selectedCustomer2.astrologicalSign;

      const matchPercentage = compatibilityMatrix[sign1]?.[sign2] || 0;
      this.setState({ matchPercentage });
    } else {
      this.setState({ matchPercentage: 0 });
    }
  };

  renderZodiacIcon = (sign: string | null) => {
    if (!sign || !zodiacIcons[sign])
      return null;

    const IconComponent = zodiacIcons[sign];
    return (
      <div className="zodiac-icon-container">
        <IconComponent className="zodiac-icon" />
      </div>
    );
  };

  selectUser =(userId: number) => {
    this.setState({ selected: userId });
  }

  closeLeftModal = () => {
    this.setState({ leftModalOpen: false, selected: undefined });
  };

  closeRightModal = () => {
    this.setState({ rightModalOpen: false, selected: undefined });
  };

  render() {
    const { customers, selectedCustomer1, selectedCustomer2, matchPercentage, status, message } = this.state;

    const availableCustomers1 = customers.filter(customer => customer !== selectedCustomer2);
    const availableCustomers2 = customers.filter(customer => customer !== selectedCustomer1);

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
        <div className='astro'>
          <div className="astro-match-container">
            <div className="left-column">
              <Button text="Select first customer" onClick={() => this.setState({ leftModalOpen: true })} color="secondary" />
              <Modal
                open={this.state.leftModalOpen}
                onClose={this.closeLeftModal}
                title="Select customers"
                fullWidth
                fullHeight
                actions={
                  <Button
                    text="Apply"
                    onClick={this.handleCustomerChange('first')}
                    color='secondary'
                    size='small'
                  />
                }
              >
                <div className="customer-photos">
                  {availableCustomers1.map((customer: Customer, index) => (
                    <div key={index} className={this.state.selected === customer.id ? "selected-customer" : ""} onClick={() => this.selectUser(customer.id)}>
                      <Card
                        title={customer.fullName}
                        subtitle={customer.astrologicalSign}
                        content=""
                        imageUrl={customer.image ? ('data:image/png;base64, ' + customer.image) : `https://via.placeholder.com/300x300.png?text=No+image`}
                        imageAlt={customer.fullName}
                        imageHeight={300}
                      />
                    </div>
                  ))}
                </div>
              </Modal>

              {selectedCustomer1 && (
                <Card
                  title={selectedCustomer1.fullName}
                  subtitle={selectedCustomer1.astrologicalSign}
                  content=""
                  imageUrl={selectedCustomer1.image ? ('data:image/png;base64, ' + selectedCustomer1.image) : `https://via.placeholder.com/300x300.png?text=No+image`}
                  imageAlt={selectedCustomer1.fullName}
                  imageHeight={300}
                />
              )}
            </div>

            {selectedCustomer1 ?
              (this.renderZodiacIcon(selectedCustomer1.astrologicalSign) || (<div className="zodiac-icon-container" />)) :
              (<div className="zodiac-icon-container" />)
            }

            <div className="match-percentage-container">
              <div className="match-percentage-heart">
                <div className="match-percentage-score">
                  {matchPercentage}%
                </div>
              </div>
            </div>

            {selectedCustomer2 ?
              (this.renderZodiacIcon(selectedCustomer2.astrologicalSign) || (<div className="zodiac-icon-container" />)) :
              (<div className="zodiac-icon-container" />)
            }

            <div className="right-column">
              <Button text="Select second customer" onClick={() => this.setState({ rightModalOpen: true })} color='secondary' />
                <Modal
                  open={this.state.rightModalOpen}
                  onClose={this.closeRightModal}
                  title="Select customers"
                  fullWidth
                  fullHeight
                  actions={
                    <Button
                      text="Apply"
                      onClick={this.handleCustomerChange('second')}
                      color='secondary'
                      size='small'
                    />
                  }
                >
                  <div className="customer-photos">
                    {availableCustomers2.map((customer: Customer, index) => (
                      <div key={index} className={this.state.selected === customer.id ? "selected-customer" : ""} onClick={() => this.selectUser(customer.id)}>
                        <Card
                          title={customer.fullName}
                          subtitle={customer.astrologicalSign}
                          content=""
                          imageUrl={customer.image ? ('data:image/png;base64, ' + customer.image) : `https://via.placeholder.com/300x300.png?text=No+image`}
                          imageAlt={customer.fullName}
                          imageHeight={300}
                        />
                      </div>
                    ))}
                  </div>
                </Modal>

              {selectedCustomer2 && (
                <Card
                  title={selectedCustomer2.fullName}
                  subtitle={selectedCustomer2.astrologicalSign}
                  content=""
                  imageUrl={selectedCustomer2.image ? ('data:image/png;base64, ' + selectedCustomer2.image) : `https://via.placeholder.com/300x300.png?text=No+image`}
                  imageAlt={selectedCustomer2.fullName}
                  imageHeight={300}
                />
              )}
            </div>
          </div>
        </div>
        break;
    }
    return (
      <Page pageTitle="Astrological match">
        {renderElement}
      </Page>
    );
  }
}
