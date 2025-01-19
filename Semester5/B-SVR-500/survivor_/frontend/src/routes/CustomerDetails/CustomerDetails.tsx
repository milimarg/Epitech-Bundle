import React from 'react';
import { NavigateFunction, useLocation, useNavigate } from 'react-router-dom';
import Page from '../../components/Page/Page';
import TableComponent from '../../components/Table/Table';
import BackendRequester from '../../utils/backendRequester';
import AvatarComponent from '../../components/Avatar/Avatar';
import { Divider, Card, CardContent, Typography, Grid2, Rating } from '@mui/material';
import CircularProgress from '@mui/material/CircularProgress';
import { Customer, Encounter, PaymentHistory as Payment } from '../../utils/types';
import MailIcon from '@mui/icons-material/MailOutline';
import BookmarkIcon from '@mui/icons-material/BookmarkAddOutlined';
import ArrowBackIcon from '@mui/icons-material/ArrowBack';
import Button from '../../components/Button/Button';
import './CustomerDetails.css';
import moment from 'moment';

type Props = {
  customer: Customer;
  navigate: NavigateFunction;
};

type State = {
  payments: Payment[],
  encounters: Encounter[],
  status: "loading" | "success" | "error",
  message?: string
};

class CustomerDetails extends React.Component<Props, State> {
  state: State = {
    payments: [],
    encounters: [],
    status: "loading"
  };

  async componentDidMount() {
    const { customer } = this.props;

    try {
      let payments: Payment[] = [];
      let encounters: Encounter[] = [];
      try {
        const paymentsTmp = await BackendRequester.fetchCustomerPaymentsData(customer.id);
        const encountersTmp = await BackendRequester.fetchCustomerMeetingsData(customer.id);

        if (BackendRequester.isFetchError(paymentsTmp)) {
          this.setState({ status: "error", message: paymentsTmp.type + " " + paymentsTmp.message });
          return;
        }
        if (Array.isArray(paymentsTmp)) {
          payments = paymentsTmp;
        } else {
          this.setState({ status: "error", message: "Error fetching payments data: Invalid data" });
          return;
        }

        let encounterArray: Encounter[] = [];
        if (BackendRequester.isFetchError(encountersTmp)) {
          this.setState({ status: "error", message: encountersTmp.type + " " + encountersTmp.message });
          return;
        }
        if (encountersTmp !== undefined && typeof encountersTmp === 'object') {
          if (Array.isArray(encountersTmp)) {
            encounterArray = encountersTmp;
          } else {
            encounterArray = [encountersTmp];
          }
        } else {
          this.setState({ status: "error", message: "Error fetching encounters data: Invalid data" });
          return;
        }
        encounters = encounterArray.map((meeting) => {
          return {
            ...meeting
          };
        });
      } catch (error) {
        this.setState({ status: "error", message: "Error fetching payments/encounters data:" + error });
        return;
      }
      this.setState({ payments, encounters, status: "success" });

    } catch (error) {
      this.setState({ status: "error", message: "Error fetching customers data:" + error });
    }
  }

  formatDate(dateStr: string) {
    return moment(dateStr).format('D MMM, YYYY');
  }

  formatAmount(amount: number) {
    const formattedAmount = Math.abs(amount).toFixed(2);
    return amount >= 0 ? `- $${formattedAmount}` : `+ $${formattedAmount}`;
  }

  formatUserId(id: number): string {
    return `UD${id.toString().padStart(6, '0')}`;
  }

  render() {
    const { customer, navigate } = this.props;
    const { payments, encounters, status, message } = this.state;

    const handleBackClick = () => {
      navigate(-1);
    };

    const totalEncounters = encounters.length;
    const positiveEncounters = encounters.filter(encounter => encounter.rating >= 3).length;
    const inProgressEncounters = encounters.filter(encounter => encounter.comment === "In progress").length;

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
        renderElement = (
          <div className="customer-details-page">
            <div className="header-button-container">
              <Button
                text="Back"
                startIcon={<ArrowBackIcon />}
                onClick={handleBackClick}
                size="small"
                color="secondary"
              />
            </div>
            <Card className="customer-card">
              <CardContent>
                <Grid2 container spacing={2} direction="column" alignItems="center">
                  <Grid2>
                    <AvatarComponent
                      src={customer?.image ? `data:image/png;base64, ${customer.image}` : ''}
                      alt={`${customer.name} ${customer.surname}`}
                      size="xlarge"
                      name={customer.name}
                      surname={customer.surname}
                    />
                  </Grid2>
                  <Grid2>
                    <Typography variant="h6" fontWeight="bold">
                      {`${customer.name} ${customer.surname}`}
                    </Typography>
                  </Grid2>

                  <div className="divider-fullwidth">
                    <Divider />
                  </div>

                  <Grid2 container justifyContent="center" spacing={2} alignItems="center">
                    <Grid2>
                      <MailIcon />
                    </Grid2>
                    <Grid2>
                      <BookmarkIcon />
                    </Grid2>
                  </Grid2>

                  <div className="divider-fullwidth">
                    <Divider />
                  </div>

                  <Grid2 container justifyContent="space-between" spacing={2} className="customer-counters">
                    <Grid2 container direction="column" alignItems="center" textAlign="center">
                      <Typography variant="h4">{totalEncounters}</Typography>
                      <Typography variant="subtitle1">Total Encounters</Typography>
                    </Grid2>
                    <Grid2 container direction="column" alignItems="center" textAlign="center">
                      <Typography variant="h4">{positiveEncounters}</Typography>
                      <Typography variant="subtitle1">Positives</Typography>
                    </Grid2>
                    <Grid2 container direction="column" alignItems="center" textAlign="center">
                      <Typography variant="h4">{inProgressEncounters}</Typography>
                      <Typography variant="subtitle1">In Progress</Typography>
                    </Grid2>
                  </Grid2>

                  <div className="divider-fullwidth">
                    <Divider />
                  </div>

                  <Typography
                    variant="subtitle1"
                    fontWeight="bold"
                    align="left"
                  >
                    Short details
                  </Typography>

                  <Grid2>
                    <Typography variant="subtitle1"><b>User ID</b>:</Typography>
                    <Typography variant="body2">{this.formatUserId(customer.id)}</Typography>
                    <br />

                    <Typography variant="subtitle1"><b>Email</b>:</Typography>
                    <Typography variant="body2">{customer.email}</Typography>
                    <br />

                    <Typography variant="subtitle1"><b>Address</b>:</Typography>
                    <Typography variant="body2">{customer.address}</Typography>
                    <br />

                    <Typography variant="subtitle1"><b>Last Activity</b>:</Typography>
                    <Typography variant="body2">Placeholder</Typography>
                    <br />

                    <Typography variant="subtitle1"><b>Coach</b>:</Typography>
                    <Typography variant="body2">Placeholder</Typography>
                  </Grid2>
                </Grid2>
              </CardContent>
            </Card>

            <Card className="customer-table-card">
              <CardContent>

                <Typography variant="h6" fontWeight="bold">Recent Meetings</Typography>
                <br />
                <TableComponent
                  columns={['Date', 'Rating', 'Report', 'Source']}
                  data={encounters.map(encounter => ({
                    Date: this.formatDate(encounter.date),
                    Rating: <Rating value={encounter.rating} readOnly />,
                    Report: encounter.comment,
                    Source: encounter.source
                  }))}
                />

                <br />
                <br />

                <Typography variant="h6" fontWeight="bold">Payments History</Typography>
                <br />
                <TableComponent
                  columns={['Date', 'Payment Method', 'Amount', 'Comment']}
                  data={payments.map(payment => ({
                    Date: this.formatDate(payment.date),
                    'Payment Method': "None",
                    Amount: this.formatAmount(payment.amount),
                    Comment: payment.comment,
                  }))}
                />
              </CardContent>
            </Card>
          </div>
        );
        break;
    }

    return (
      <Page pageTitle="Customer Details">
        {renderElement}
      </Page>
    );
  }
}

const CustomerDetailsBridge: React.FC = () => {
  const location = useLocation();
  const customer = location.state;
  const navigate = useNavigate();

  if (!customer)
    return <div>No customer data available</div>;

  return <CustomerDetails customer={customer} navigate={navigate} />;
};

export default CustomerDetailsBridge;
