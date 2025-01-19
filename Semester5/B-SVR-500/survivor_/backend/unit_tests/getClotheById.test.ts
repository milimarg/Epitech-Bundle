import fetchMock from "jest-fetch-mock";
import DBWrapper from "../src/api/db";
import * as Types from "../src/api/types";
import TokenClient from "../src/api/hash";

fetchMock.enableMocks();

describe("getClotheById", () => {
  let dbWrapper: DBWrapper;

  beforeEach(() => {
    fetchMock.resetMocks();
    dbWrapper = new DBWrapper;
  });

  it("shouldn't return clothes when token has not enough permissions", async () => {
    const fakeResponse = {"message": "Bad permissions"};
    const response = await dbWrapper.getClotheById("miaou", 1);

    expect(response.message).toBe(fakeResponse.message);
  });

  it("shouldn't return clothe when clothe doesn't exist", async () => {
    const fakeResponse = {"message": "Clothe doesn't exist"};
    const login = "etienne.roussel@soul-connection.fr";
    const password = "kaguyaSamaL0VEIsWar2015";

    const token = await dbWrapper.loginClient(login, password);

    if (!token.var)
      return;

    const response = await dbWrapper.getClotheById(token.var, 424242);

    expect(response.message).toBe(fakeResponse.message);
  });

  it("should return clothe when token has enough permissions", async () => {
    const fakeResponse = {"message": "Success"};
    const login = "etienne.roussel@soul-connection.fr";
    const password = "kaguyaSamaL0VEIsWar2015";

    const token = await dbWrapper.loginClient(login, password);

    if (!token.var)
      return;

    const response = await dbWrapper.getClotheById(token.var, 1);

    expect(response.message).toBe(fakeResponse.message);
  });
});
