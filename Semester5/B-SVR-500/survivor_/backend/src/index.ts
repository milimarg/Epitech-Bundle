import express from 'express';
import cors from 'cors';
import dotenv from 'dotenv';
import bodyParser from 'body-parser';
import APIWrapper from "./api/api"
import DBWrapper from "./api/db";

const wrapper = new APIWrapper;
export const dbWrapper = new DBWrapper;

const getEmployees = require("./routes/GET/employees/getEmployees");
const employeeSignup = require("./routes/POST/employees/signupEmployee");
const employeeLogin = require("./routes/POST/employees/loginEmployee");
const employeeDelete = require("./routes/DELETE/employees/deleteEmployee");
const getEmployeeMe = require("./routes/GET/employees/getEmployeeMe");
const getEmployeeShortMe = require("./routes/GET/employees/getEmployeeShortMe");
const getEmployeeById = require("./routes/GET/employees/getEmployeeById");
const getEmployeeImage = require("./routes/GET/employees/image/getEmployeeImage");

const getCustomers = require("./routes/GET/customers/getCustomers");
const getCustomersShort = require("./routes/GET/customers/getCustomersShort");
const getCustomerMe = require("./routes/GET/customers/getCustomerMe");
const getCustomerShortMe = require("./routes/GET/customers/getCustomerShortMe");
const getCustomerById = require("./routes/GET/customers/getCustomerById");
const getCustomerImage = require("./routes/GET/customers/image/getCustomerImage");
const getCustomerPaymentsHistory = require("./routes/GET/customers/payments_history/getCustomerPayment");
const getPaymentsHistory = require("./routes/GET/customers/payments_history/getPaymentsHistory");
const createCustomer = require("./routes/POST/customers/signupCustomer");
const deleteCustomer = require("./routes/DELETE/customers/deleteCustomer");
const assignCustomersToEmployee = require("./routes/PUT/employees/updateAssignedCustomers");

const getEncounters = require("./routes/GET/encounters/getEncounters");
const getEncounterById = require("./routes/GET/encounters/getEncounterById");
const getEncounterOfCustomerById = require("./routes/GET/encounters/customer/getEncounterByCustomer");

const getTips = require("./routes/GET/tips/getTips");

const getEvents = require("./routes/GET/events/getEvents");
const getEventsById = require("./routes/GET/events/getEventsById");
const getEventsByIdComments = require("./routes/GET/events/getEventsByIdComments");
const getEventsByIdSubscribers = require("./routes/GET/events/getEventsByIdSubscribers");
const addCommentEventById = require("./routes/PUT/events/addCommentEventById");
const removeCommentEventById = require("./routes/PUT/events/removeCommentEventById");
const subscribedToEvent = require("./routes/PUT/events/subscribedToEvent");
const unsubscribedToEvent = require("./routes/PUT/events/unsubscribedToEvent");
const setLimitEvent = require("./routes/PUT/events/setLimitEvent");

const getClothes = require("./routes/GET/customers/clothes/getClothes");
const getShortClothes = require("./routes/GET/customers/clothes/getClothesShort");
const getClotheById = require("./routes/GET/customers/clothes/getClotheById");
const getClotheImageById = require("./routes/GET/customers/clothes/getClotheImageById");
const getClothesByCustomer = require("./routes/GET/customers/clothes/getClothesByCustomer");
const getClothesTypeByCustomer = require("./routes/GET/customers/clothes/getClothesTypeByCustomer");

dotenv.config();

const app = express();
const port = process.env.PORT ?? 5000;

app.use(cors());
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({
  extended: true
}));

app.use(getEmployees);
app.use(employeeSignup);
app.use(employeeLogin);
app.use(employeeDelete);
app.use(getEmployeeMe);
app.use(getEmployeeShortMe);
app.use(getEmployeeById);
app.use(getEmployeeImage);
app.use(assignCustomersToEmployee);

app.use(getCustomers);
app.use(getCustomersShort);
app.use(getCustomerMe);
app.use(getCustomerShortMe);
app.use(getCustomerById);
app.use(getCustomerImage);
app.use(getCustomerPaymentsHistory);
app.use(getPaymentsHistory);

app.use(createCustomer);
app.use(deleteCustomer);

app.use(getEncounters);
app.use(getEncounterById);
app.use(getEncounterOfCustomerById);

app.use(getTips);

app.use(getEvents);
app.use(getEventsById);
app.use(getEventsByIdComments);
app.use(getEventsByIdSubscribers);
app.use(addCommentEventById);
app.use(removeCommentEventById);
app.use(subscribedToEvent);
app.use(unsubscribedToEvent);
app.use(setLimitEvent);

app.use(getClothes);
app.use(getShortClothes);
app.use(getClotheById);
app.use(getClotheImageById);
app.use(getClothesByCustomer);
app.use(getClothesTypeByCustomer);

app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});

async function createUser()
{
  const token = process.env.TOKEN;
  const email = process.env.EMAIL;
  const password = process.env.PASSWORD;
  const adminEmail = process.env.ADMIN_EMAIL;
  const adminPassword = process.env.ADMIN_PASSWORD;
  const customerEmail = process.env.CUSTOMER_EMAIL;
  const customerPassword = process.env.CUSTOMER_PASSWORD;


  if (token) {
      if (email && password)
        dbWrapper.createCredentials({
          id: 1,
          email: email,
          permission: "COACH"
        }, password).then();
      if (adminEmail && adminPassword)
        dbWrapper.createCredentials({
          id: 2,
          email: adminEmail,
          permission: "ADMIN"
        }, adminPassword).then();
      if (customerEmail && customerPassword)
        dbWrapper.createCredentials({
          id: 3,
          email: customerEmail,
          permission: "CUSTOMER"
        }, customerPassword).then();
  }
}

async function login()
{
  const email = process.env.EMAIL ?? "";
  const password = process.env.PASSWORD ?? "";

  try {
    const data = await wrapper.login(email, password);
    console.log("Login successefully")
    wrapper.fetchLocalData(data);
    console.log("Fetching successefully")
    createUser();
    console.log("User created");
  } catch (error) {
    console.error((error as Error).message);
    console.log("No fetch will be make with the API");
  }
}

login();
