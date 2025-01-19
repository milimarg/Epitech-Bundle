import React from 'react';
import Page from '../../components/Page/Page';
import DropDown from '../../components/DropDown/DropDown';
import Modal from '../../components/Modal/Modal';
import CircularProgress from '@mui/material/CircularProgress';
import './Wardrobe.css';
import { ReactComponent as HatCapIcon } from './clothes/hat.svg';
import { ReactComponent as PersonIcon } from './clothes/person.svg';
import { ReactComponent as TopIcon } from './clothes/shirt.svg';
import { ReactComponent as BottomIcon } from './clothes/pants.svg';
import { ReactComponent as ShoesIcon } from './clothes/shoes.svg';
import BackendRequester from '../../utils/backendRequester';

type ClothingType = 'hat/cap' | 'top' | 'bottom' | 'shoes';

interface Clothe {
  customer_id: number,
  id: number,
  type: string,
  source: string | null
};

type Customer = {
  id: number,
  name: string,
  surname: string,
  fullName: string,
  image: string,
  clothes?: Clothe[]
};

type Props = {};

type State = {
  customers: Customer[],
  selectedCustomer: Customer | null,
  selectedHatCap: string | null,
  selectedTop: string | null,
  selectedBottom: string | null,
  selectedShoes: string | null,
  modalOpen: boolean,
  modalCategory: ClothingType | null,
  helperModalOpen: boolean,
  selectedItemUrl: string | null,
  status: "loading" | "success" | "error",
  message?: string
};

export default class Wardrobe extends React.Component<Props, State> {
  state: State = {
    customers: [],
    selectedCustomer: null,
    selectedHatCap: null,
    selectedTop: null,
    selectedBottom: null,
    selectedShoes: null,
    modalOpen: false,
    modalCategory: null,
    helperModalOpen: false,
    selectedItemUrl: null,
    status: "loading"
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
          });
        })
        this.setState({ customers: newCustomers, status: "success" });
      } else
        this.setState({ status: "error", message: "Error fetching customers data: Invalid response" });
    } catch (error) {
      this.setState({ status: "error", message: "Error fetching customers data:" + error });
    }
  }

  async getCustomerClothes(customer: Customer) {
    try {
      const clothes = await BackendRequester.fetchClothByCustomerId(customer.id);

      if (BackendRequester.isFetchError(clothes)) {
        this.setState({ status: "error", message: clothes.type + " " + clothes.message });
        return;
      }
      customer.clothes = clothes;
      if (Array.isArray(clothes)) {
        this.setState((prevState) => ({
          customers: prevState.customers.map((checkedCustomer) => {
            if (checkedCustomer.id === customer.id)
              checkedCustomer.clothes = clothes;
            return checkedCustomer;
          })
        }));
      } else
        this.setState({ status: "error", message: "Error fetching clothes data: Invalid response" });
    } catch (error) {
      this.setState({ status: "error", message: "Error fetching tips data:" + error });
    }
  }

  handleCustomerChange = (event: React.ChangeEvent<HTMLInputElement>) => {
    const selectedCustomer = this.state.customers.find(
      (customer) => customer.fullName === event.target.value
    );

    if (selectedCustomer) {
      this.setState({
        selectedCustomer,
        selectedHatCap: null,
        selectedTop: null,
        selectedBottom: null,
        selectedShoes: null
      });

      this.getCustomerClothes(selectedCustomer).then((e) => {
      });
    }
  };

  openModal = (category: ClothingType) => {
    this.setState({
      modalOpen: true,
      modalCategory: category,
      selectedItemUrl: this.getSelectedItem(category)
    });
  };

  closeModal = () => {
    this.setState({ modalOpen: false, modalCategory: null });
  };

  selectClothingItem = (itemUrl: string) => {
    const { selectedItemUrl } = this.state;

    if (itemUrl === selectedItemUrl) {
      this.setState({ selectedItemUrl: null });
    } else {
      this.setState({ selectedItemUrl: itemUrl });
    }
  };

  resetSelection = (modalCategory: ClothingType) => {
    switch (modalCategory) {
      case 'hat/cap':
        this.setState({ selectedHatCap: null });
        break;
      case 'top':
        this.setState({ selectedTop: null });
        break;
      case 'bottom':
        this.setState({ selectedBottom: null });
        break;
      case 'shoes':
        this.setState({ selectedShoes: null });
        break;
    }
  }

  applySelection = () => {
    const { modalCategory, selectedItemUrl } = this.state;
    if (modalCategory && selectedItemUrl) {
      switch (modalCategory) {
        case 'hat/cap':
          this.setState({ selectedHatCap: selectedItemUrl });
          break;
        case 'top':
          this.setState({ selectedTop: selectedItemUrl });
          break;
        case 'bottom':
          this.setState({ selectedBottom: selectedItemUrl });
          break;
        case 'shoes':
          this.setState({ selectedShoes: selectedItemUrl });
          break;
        default:
          break;
      }
    } else if (modalCategory && !selectedItemUrl) {
      this.resetSelection(modalCategory);
    }

    this.setState({
      modalOpen: false,
      modalCategory: null,
      selectedItemUrl: null
    });
  };

  openHelperModal = () => {
    this.setState({ helperModalOpen: true });
  };

  closeHelperModal = () => {
    this.setState({ helperModalOpen: false });
  };

  renderClothingSquare = (icon: React.ReactNode, selectedImage: string | null, onClick: () => void, key: string) => {
    return (
      <div
        className="clothing-square"
        onClick={onClick}
        key={key}
      >
        {selectedImage ? (
          <img src={'data:image/png;base64, ' + selectedImage} alt="Selected clothing" className="clothing-image" />
         ) : (
          <div className="clothing-square-icon">
            {icon}
          </div>
        )}
      </div>
    );
  };

  getSelectedItem = (category: ClothingType | null) => {
    const { selectedHatCap, selectedTop, selectedBottom, selectedShoes } = this.state;

    switch (category) {
      case 'hat/cap':
        return selectedHatCap;
      case 'top':
        return selectedTop;
      case 'bottom':
        return selectedBottom;
      case 'shoes':
        return selectedShoes;
      default:
        return null;
    }
  };

  getClothingOptions = () => {
    const { selectedCustomer, modalCategory } = this.state;
    if (selectedCustomer && modalCategory) {
      if (selectedCustomer.clothes === undefined)
        return [];

      const clothes = selectedCustomer.clothes
        .filter(clothing => clothing.type === modalCategory)
        .map(clothing => clothing.source ?? '')

      return clothes;
    }
    return [];
  };

  render() {
    const {
      customers,
      selectedCustomer,
      selectedHatCap,
      selectedTop,
      selectedBottom,
      selectedShoes,
      modalOpen,
      modalCategory,
      helperModalOpen,
      selectedItemUrl,
      status,
      message
    } = this.state;

    const clothingOptions = this.getClothingOptions();
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
        <div className='wardrobe'>
          <div className="dropdown-container">
            <DropDown
              label="Select customer"
              options={customers.map((customer) => ({ value: customer.fullName, label: customer.fullName }))}
              value={selectedCustomer?.fullName ?? ''}
              onChange={this.handleCustomerChange}
              fullWidth
            />
          </div>
          <div className="wardrobe-container">

            <div className="wardrobe-content">
              {this.renderClothingSquare(<HatCapIcon />, selectedHatCap, () => { if (selectedCustomer) this.openModal('hat/cap') }, 'hat/cap-square')}
              {this.renderClothingSquare(<PersonIcon />, selectedCustomer?.image ?? null, () => {}, 'person-square')}
              {this.renderClothingSquare(<TopIcon />, selectedTop, () => { if (selectedCustomer) this.openModal('top') }, 'top-square')}
              {this.renderClothingSquare(<BottomIcon />, selectedBottom, () => { if (selectedCustomer) this.openModal('bottom') }, 'bottom-square')}
              {this.renderClothingSquare(<ShoesIcon />, selectedShoes, () => { if (selectedCustomer) this.openModal('shoes') }, 'shoes-square')}
            </div>

            <Modal
              open={modalOpen}
              onClose={this.closeModal}
              title={`Select ${modalCategory}`}
              fullWidth
              fullHeight
              actions={
                <button onClick={this.applySelection}>Apply</button>
              }
            >

              <div className="clothing-options">
                {clothingOptions.map((item, index) => (
                  <div
                    key={index}
                    className={`clothing-item ${selectedItemUrl === item ? 'selected' : ''}`}
                    onClick={() => this.selectClothingItem(item)}
                  >
                    <img src={'data:image/png;base64, ' + item} alt="Clothing Option" />
                  </div>
                ))}
              </div>
            </Modal>
          </div>
          <button className="helper-button" onClick={this.openHelperModal}>?</button>
          <Modal
            open={helperModalOpen}
            onClose={this.closeHelperModal}
            title="How to use wardrobe"
            fullWidth
            fullHeight
          >
            <p>Select a customer and choose different clothes for them by clicking on the squares. You can change the hat, shirt, pants, and shoes.</p>
          </Modal>
        </div>
        break;
    }
    return (
      <Page pageTitle="Wardrobe">
        {renderElement}
      </Page>
    );
  }
}
