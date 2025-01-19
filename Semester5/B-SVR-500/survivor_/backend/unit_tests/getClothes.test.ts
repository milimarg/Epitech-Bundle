import fetchMock from "jest-fetch-mock";
import DBWrapper from "../src/api/db";
import * as Types from "../src/api/types";
import TokenClient from "../src/api/hash";

fetchMock.enableMocks();

describe("getClothes", () => {
  let dbWrapper: DBWrapper;

  beforeEach(() => {
    fetchMock.resetMocks();
    dbWrapper = new DBWrapper;
  });

  it("shouldn't return clothes when token has not enough permissions", async () => {
    const fakeResponse = {"message": "Bad permissions"};
    const response = await dbWrapper.getClothes("miaou");

    expect(response.message).toBe(fakeResponse.message);
  });

  it("should return clothes when token has enough permissions", async () => {
    const fakeResponse = {"message": "Success"};
    const login = "etienne.roussel@soul-connection.fr";
    const password = "kaguyaSamaL0VEIsWar2015";

    const token = await dbWrapper.loginClient(login, password);

    if (!token.var)
      return;

    const response = await dbWrapper.getClothes(token.var);

    expect(response.message).toBe(fakeResponse.message);
  });
});
