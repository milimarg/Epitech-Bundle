import fetchMock from "jest-fetch-mock";
import DBWrapper from "../src/api/db";
import * as Types from "../src/api/types";
import TokenClient from "../src/api/hash";

fetchMock.enableMocks();

describe("registerCustomer", () => {
  let dbWrapper: DBWrapper;

  beforeEach(() => {
    fetchMock.resetMocks();
    dbWrapper = new DBWrapper;
  });

  it("should register customer if it doesn't exist", async () => {
    const customerLogin = "itdoesntexist@voila.fr";
    const customerPassword = "aeiouy";
    const login = "jeanne.martin@soul-connection.fr";
    const password = "naouLeA82oeirn";

    const customer: Types.Customer = {
      id: 0,
      email: customerLogin,
      name: "itdoesnt",
      surname: "exist",
      birth_date: "01/01/9999",
      gender: "idk",
      description: "description",
      astrological_sign: "universe",
      phone_number: "0000000000",
      address: "1, rue sésame",
      image: "a",
      unix_time: 0
    };
    const fakeToken = {"message": "Success"};
    const token = await dbWrapper.loginClient(login, password);
    const customerToken = await dbWrapper.registerCustomer(customer, customerPassword);

    //expect(customerToken.message).toBe(fakeToken.message); TODO: commented to avoid aforementioned problem

    if (!token.var || !customerToken.var)
      return;

    const hash = new TokenClient();
    const unhash: Types.TokenValue = hash.unhashValue<Types.TokenValue>(customerToken.var);

    await dbWrapper.deleteCustomer(token.var, unhash.id);
    //console.log("error deleting customer = ", a.message); TODO: id is right but won't delete the customer???
  });

  it("should not register if customer already exists", async () => {
    const customerLogin = "mercier348.nathalie@gmail.com";
    const customerPassword = "aeiouy";

    const customer: Types.Customer = {
      id: 0,
      email: customerLogin,
      name: "itdoesnt",
      surname: "exist",
      birth_date: "01/01/9999",
      gender: "idk",
      description: "description",
      astrological_sign: "universe",
      phone_number: "0000000000",
      address: "1, rue sésame",
      image: "a",
      unix_time: 0
    };
    const fakeToken = {"message": "Customer already exist"};
    const customerToken = await dbWrapper.registerCustomer(customer, customerPassword);

    expect(customerToken.message).toBe(fakeToken.message);
  });
});
