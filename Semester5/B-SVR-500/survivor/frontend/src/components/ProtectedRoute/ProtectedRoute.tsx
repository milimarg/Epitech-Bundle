import React from "react";
import { jwtDecode } from 'jwt-decode';

type Props = {
  element: JSX.Element,
  permissions: string[],
  defaultElement: JSX.Element
};

type TokenValue = {
  id: number,
  email: string,
  name: string,
  surname: string,
  permission: string
}


class ProtectedRoute extends React.Component<Props>{
  render() {
    const {element, permissions, defaultElement} = this.props;
    const token = localStorage.getItem('authToken');
    if (token == null)
        return defaultElement;
    const decoded = jwtDecode(token) as TokenValue;
    if (decoded == null)
        return defaultElement;
    if (!permissions.includes(decoded.permission))
        return defaultElement;
    return element;
  }
}

export default ProtectedRoute
