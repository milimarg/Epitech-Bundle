import fetchMock from "jest-fetch-mock";
import DBWrapper from "../src/api/db";
import * as Types from "../src/api/types";
import {TokenValue} from "../src/api/types";
import TokenClient from "../src/api/hash";

fetchMock.enableMocks();

describe("deleteEmployee", () => {
  let dbWrapper: DBWrapper;

  beforeEach(() => {
    fetchMock.resetMocks();
    dbWrapper = new DBWrapper;
  });

  it("should not delete employee if not enough permissions", async () => {
    const fakeToken = {"message": "Bad permissions"};
    const customerLogin = "labbe636.josette@outlook.com";
    const customerPassword = "uflefoudubus";

    const customerToken = await dbWrapper.loginClient(customerLogin, customerPassword);

    if (!customerToken.var)
      return;

    const a = await dbWrapper.deleteCustomer(customerToken.var, 42);

    expect(a.message).toBe(fakeToken.message);
  });
});
