import fetchMock from "jest-fetch-mock";
import DBWrapper from "../src/api/db";
import * as Types from "../src/api/types";
import {TokenValue} from "../src/api/types";
import TokenClient from "../src/api/hash";

fetchMock.enableMocks();

describe("deleteCustomer", () => {
  let dbWrapper: DBWrapper;

  beforeEach(() => {
    fetchMock.resetMocks();
    dbWrapper = new DBWrapper;
  });

  it("should not delete customer if not enough permissions", async () => {
    const fakeToken = {"message": "Bad permissions"};
    const customerLogin = "etienne.roussel@soul-connection.fr";
    const customerPassword = "kaguyaSamaL0VEIsWar2015";

    const customerToken = await dbWrapper.loginClient(customerLogin, customerPassword);

    if (!customerToken.var)
      return;

    const a = await dbWrapper.deleteEmployee(customerToken.var, 42);

    expect(a.message).toBe(fakeToken.message);
  });
});
