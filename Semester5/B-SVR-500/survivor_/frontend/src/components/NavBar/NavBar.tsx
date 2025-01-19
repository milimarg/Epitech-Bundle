import React from "react";
import { Tab, Tabs, IconButton } from "@mui/material";
import AppBar from '@mui/material/AppBar';
import Typography from '@mui/material/Typography';
import MessageIcon from '@mui/icons-material/Message';
import Avatar from '@mui/material/Avatar';
import './NavBar.css';
import logoutImage from './logout.png';
import BackendRequester from "../../utils/backendRequester";
import { Customer } from '../../utils/types';


type ButtonInfo = {
  text: string;
  onClick: () => void;
  route: string;
};

type Props = {
  buttons: ButtonInfo[];
};

type State = {
  selectedTab: number;
  customer?: Customer
};

const style = {
  display: 'flex',
  flexDirection: 'row',
  height: '5rem',
  justifyContent: 'space-between',
  alignItems: 'center',
};

class NavBar extends React.Component<Props, State> {
  state: State = {
    selectedTab: 0,
  };

  async componentDidMount() {
    this.updateSelectedTab();
    window.addEventListener('popstate', this.updateSelectedTab);
    try {
      const customer = await BackendRequester.fetchCustomerInfoMe();
      if (!BackendRequester.isFetchError(customer))
        this.setState({ customer });
    } catch (error) {
      return;
    }
  }

  componentWillUnmount() {
    window.removeEventListener('popstate', this.updateSelectedTab);
  }

  updateSelectedTab = () => {
    const { buttons } = this.props;
    const currentPath = window.location.pathname;
    const selectedTab = buttons.findIndex(button => button.route === currentPath);
    this.setState({ selectedTab: selectedTab !== -1 ? selectedTab : 0 });
  };

  handleTabChange = (event: React.ChangeEvent<{}>, newValue: number) => {
    this.setState({ selectedTab: newValue });
    const { buttons } = this.props;
    window.history.pushState(null, '', buttons[newValue].route);
  };

  handleLogout = () => {
    localStorage.removeItem('authToken');
    window.location.href = '/login';
  };

  render() {
    const { buttons } = this.props;
    const { selectedTab, customer } = this.state;

    let AvatarDiv;
    if (customer && customer.image) {
      let dataUrl = `data:image/png;base64,${customer.image}`;
      AvatarDiv = <Avatar alt="User Avatar" src={dataUrl} />
    } else {
      AvatarDiv = <Avatar alt="User Avatar" />
    }
    return (
      <div className="navbar-wrapper">
        <AppBar
          position="static"
          sx={style}
          color='secondary'
        >
          <div className="navbar">
            <Typography variant="h6" component="div" fontWeight="bold">
              Soul Connection
            </Typography>
            <Tabs value={selectedTab} onChange={this.handleTabChange}>
              {buttons.map((button, index) => (
                <Tab key={index} label={button.text} onClick={button.onClick} sx={{textTransform: 'none', color: 'black'}}/>
              ))}
            </Tabs>
            <div className="navbar-icons">
              <IconButton onClick={this.handleLogout}>
                <img src={logoutImage} alt="Custom Button" style={{ width: '30px', height: '30px' }}/>
              </IconButton>
              <MessageIcon />
              {AvatarDiv}
            </div>
          </div>
        </AppBar>
      </div>
    );
  }
}

export default NavBar;
