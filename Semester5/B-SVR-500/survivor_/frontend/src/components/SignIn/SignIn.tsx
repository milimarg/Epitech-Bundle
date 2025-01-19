import React from "react";
import Button from "../Button/Button";
import InputField from "../InputField/InputField";
import BackendRequester from '../../utils/backendRequester';
import { jwtDecode } from 'jwt-decode';
import "./SignIn.css";

type TokenValue = {
  id: number,
  email: string,
  name: string,
  surname: string,
  permission: string
}

type Props = {
    //
};

type State = {
  email: string,
  password: string,
  error: string
};

export default class SignIn extends React.Component<Props, State> {
  state: State = {
    email: "",
    password: "",
    error: ""
  };

  goToPage() {
    const token = localStorage.getItem('authToken');
    if (!token)
      return;
    const decoded = jwtDecode(token) as TokenValue;
    if (decoded == null)
        return;
    switch (decoded.permission) {
      case "COACH":
      case "ADMIN":
        window.location.href = "/home";
        break;
      case "CUSTOMER":
        window.location.href = "/events";
        break;
    }
  }

  render() {
    const { email, password, error } = this.state;
    this.goToPage();
    return (
      <div className="sign-in-container">
        <div className="sign-in-title">
            <h1>SOUL CONNECTION</h1>
        </div>
        <div className="sign-in-form">
          <InputField label="Email" type="text" value={email} onChange={(event: React.ChangeEvent<HTMLInputElement>) => {
            this.setState({
              email: event.target.value,
            });
          }} />
          <InputField label="Password" type="password" value={password} onChange={(event: React.ChangeEvent<HTMLInputElement>) => {
            this.setState({
              password: event.target.value,
            });
          }} />
          {error &&
            <div className="error-message">
              {error}
            </div>
          }
          <Button
            text="Sign In"
            size="small"
            onClick={() => {
              BackendRequester.login(email, password).then((result) => {
                if (typeof result === 'string') {
                  localStorage.setItem('authToken', result);
                  this.goToPage();
                } else {
                  this.setState({ error: "Email or password incorrect" });
                }
              }).catch(() => {
                this.setState({ error: "Email or password incorrect" });
              });
            }}
            color="secondary"
          />
        </div>
      </div>
    );
  };
}