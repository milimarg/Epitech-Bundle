import fetchMock from "jest-fetch-mock";
import DBWrapper from "../src/api/db";
import * as Types from "../src/api/types";
import {TokenValue} from "../src/api/types";
import TokenClient from "../src/api/hash";

fetchMock.enableMocks();

describe("credentialsPermissions", () => {
  let dbWrapper: DBWrapper;

  beforeEach(() => {
    fetchMock.resetMocks();
    dbWrapper = new DBWrapper;
  });

  it("should return a token when login of COACH is successful", async () => {
    const fakeToken = {"message": "Success"};
    const login = "etienne.roussel@soul-connection.fr";
    const password = "kaguyaSamaL0VEIsWar2015";

    fetchMock.mockResponseOnce(JSON.stringify({ access_token: fakeToken }));

    const token = await dbWrapper.loginClient(login, password);

    expect(token.message).toBe(fakeToken.message);

    if (!token.var)
      return;

    await dbWrapper.checkPermission(token.var, ["COACH"]).then((hasPermissions) => {
      expect(hasPermissions).toBe(true);
    });
  });

  it("should return a token when login of ADMIN is successful", async () => {
    const fakeToken = {"message": "Success"};
    const login = "jeanne.martin@soul-connection.fr";
    const password = "naouLeA82oeirn";

    fetchMock.mockResponseOnce(JSON.stringify({ access_token: fakeToken }));

    const token = await dbWrapper.loginClient(login, password);

    expect(token.message).toBe(fakeToken.message);

    if (!token.var)
      return;

    await dbWrapper.checkPermission(token.var, ["ADMIN"]).then((hasPermissions) => {
      expect(hasPermissions).toBe(true);
    });
  });

  it("should return an error when token is unhashable", async () => {
    const fakeToken = "fake123";

    await dbWrapper.checkPermission(fakeToken, ["ADMIN"]).then((hasPermissions) => {
      expect(hasPermissions).toBe(false);
    });
  });

  it("should return error when token is valid but credentials in it aren't", async () => {
    const hash = new TokenClient();
    const tokenValue: TokenValue = {id: 1, email: "ah@voila.fr", permission: "nu-huh"};
    const token = hash.hashValue<Types.TokenValue>(tokenValue);

    await dbWrapper.checkPermission(token, ["ADMIN"]).then((hasPermissions) => {
      expect(hasPermissions).toBe(false);
    });
  });

  it("should return error when login is wrong", async () => {
    const fakeToken = {"message": "Email or Password is incorrect"};
    const login = "etienne.roussel@soul-connection.fra";
    const password = "kaguyaSamaL0VEIsWar2015";

    fetchMock.mockResponseOnce(JSON.stringify({ access_token: fakeToken }));

    const token = await dbWrapper.loginClient(login, password);

    expect(token.message).toBe(fakeToken.message);
  });
});
