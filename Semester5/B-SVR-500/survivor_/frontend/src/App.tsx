import { Routes, Route, Navigate, useNavigate } from 'react-router-dom';
import Home from "./routes/Home/Home"
import Coaches from "./routes/Coaches/Coaches"
import Customers from "./routes/Customers/Customers"
import Login from "./routes/Login/Login"
import Tips from "./routes/Tips/Tips";
import Events from "./routes/Events/Events";
import AstroMatch from './routes/AstroMatch/AstroMatch';
import Wardrobe from './routes/Wardrobe/Wardrobe';
import ProtectedRoute from './components/ProtectedRoute/ProtectedRoute';
import NavBar from './components/NavBar/NavBar';
import { navbarButtons } from './utils/navbarButtons';
import { jwtDecode } from 'jwt-decode';
import CustomerDetails from './routes/CustomerDetails/CustomerDetails';
import { TokenValue } from './utils/types';
import './styles.css'

const App = () => {
  const token = localStorage.getItem('authToken');
  let tmp = navbarButtons;
  let decoded: TokenValue;
  if (token) {
    decoded = jwtDecode(token) as TokenValue;
    tmp = navbarButtons.filter(button => button.permissions.includes(decoded.permission));
  } else
    tmp = [{ text: "Login", route: "/login", permissions: ["ADMIN", "COACH", "CUSTOMER"] }];
  const navigate = useNavigate();

  return (
    <>
      <NavBar buttons={tmp.map(({text, route}) => {
        return { text, onClick: () => navigate(route), route };
      })}/>
      <div className='page-navbar-fill' />
      <Routes>
        <Route path="/login" element={<Login />} />
        <Route path="/" element={<Navigate to="/home"/>} />
        <Route
          path="/home"
          element={
            <ProtectedRoute
            element={<Home />}
            permissions={["ADMIN", "COACH", "CUSTOMER"]}
            defaultElement={<Navigate to="/login"/>}
            />}
        />
        <Route
          path="/astro-match"
          element={
            <ProtectedRoute
            element={<AstroMatch />}
            permissions={["ADMIN", "COACH"]}
            defaultElement={<Navigate to="/home"/>}
            />}
        />
        <Route
          path="/wardrobe"
          element={
            <ProtectedRoute
              element={<Wardrobe />}
              permissions={["ADMIN", "COACH"]}
              defaultElement={<Navigate to="/home"/>}
            />}
        />
        <Route
          path="/coaches"
          element={
            <ProtectedRoute
              element={<Coaches />}
              permissions={["ADMIN"]}
              defaultElement={<Navigate to="/home"/>}
            />}
        />
        <Route
          path="/customers"
          element={
            <ProtectedRoute
              element={<Customers />}
              permissions={["ADMIN", "COACH"]}
              defaultElement={<Navigate to="/home"/>}
            />}
        />
        <Route
          path="/customers/details"
          element={
            <ProtectedRoute
              element={<CustomerDetails />}
              permissions={["ADMIN", "COACH"]}
              defaultElement={<Navigate to="/home"/>}
            />}
        />
        <Route
          path="/tips"
          element={
            <ProtectedRoute
              element={<Tips />}
              permissions={["ADMIN", "COACH"]}
              defaultElement={<Navigate to="/home"/>}
            />}
        />
        <Route
          path="/events"
          element={
            <ProtectedRoute
              element={<Events />}
              permissions={["ADMIN", "COACH", "CUSTOMER"]}
              defaultElement={<Navigate to="/home"/>}
            />}
        />
      </Routes>
    </>
  );
};

  export default App;
