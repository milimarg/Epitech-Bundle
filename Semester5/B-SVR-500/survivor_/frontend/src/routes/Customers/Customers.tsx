import React from 'react';
import { useNavigate } from 'react-router-dom';
import Page from '../../components/Page/Page';
import TableComponent from '../../components/Table/Table';
import Button from '../../components/Button/Button';
import BackendRequester from '../../utils/backendRequester';
import CircularProgress from '@mui/material/CircularProgress';
import './Customers.css';
import NameAvatar from "../../components/NameAvatar/NameAvatar";
import { Customer } from '../../utils/types';


type Props = {
  onNavigateToCustomerDetails: (customer: Customer) => void;
};

type State = {
  tableData: {
    customerName: string;
    Customer: JSX.Element;
    Email: string;
    Phone: string;
    'Payment Methods': string;
    Actions: JSX.Element;
  }[],
  status: "loading" | "success" | "error",
  message?: string,
};

class Customers extends React.Component<Props, State> {
  state: State = {
    tableData: [],
    status: "loading",
  };

  async componentDidMount() {
    const { onNavigateToCustomerDetails } = this.props;

    try {
      const customers = await BackendRequester.fetchCustomersData();

      if (BackendRequester.isFetchError(customers)) {
        this.setState({ status: "error", message: customers.type + " " + customers.message });
        return;
      }
      if (Array.isArray(customers) && customers) {
        const tableData = customers.sort((a, b) => a.id - b.id).map((customer) => {
          return {
            customerName: customer.name + " " + customer.surname,
            Customer: (
              <NameAvatar
                src={!customer.image ? undefined : `data:image/png;base64, ${customer.image}`}
                alt={"customer face"}
                name={customer.name}
                surname={customer.surname}
                size={"medium"}
              />
            ),
            Email: customer.email,
            Phone: customer.phone_number,
            'Payment Methods': "None",
            Actions: (
              <Button
                text="..."
                onClick={() => onNavigateToCustomerDetails(customer)}
                size='small'
                color='secondary'
              />
            ),
          };
        });
        this.setState({ tableData, status: "success" });
      } else {
        this.setState({ status: "error", message: "Error fetching customers data: Invalid data" });
      }
    } catch (error) {
      this.setState({ status: "error", message: "Error fetching customers data:" + error });
    }
  }

  render() {
    const columnContent = ['Customer', 'Email', 'Phone', 'Payment Methods', 'Actions'];
    const { status, message, tableData } = this.state;

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
                suggestions: tableData.map((data) => data.customerName),
                searchDataKeys: ["customerName", "Email", "Phone"]
              }}
              />
          </div>
        </div>
        break;
    }

    return (
      <Page pageTitle="Customers List">
        {renderElement}
      </Page>
    );
  }
}

const CustomersWrapper: React.FC = () => {
  const navigate = useNavigate();

  const handleNavigateToCustomerDetails = (customer: Customer) => {
    navigate(`/customers/details`, { state: customer });
  };

  return <Customers onNavigateToCustomerDetails={handleNavigateToCustomerDetails} />;
};

export default CustomersWrapper;
