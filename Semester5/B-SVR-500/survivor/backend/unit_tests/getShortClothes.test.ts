import fetchMock from "jest-fetch-mock";
import DBWrapper from "../src/api/db";
import * as Types from "../src/api/types";
import TokenClient from "../src/api/hash";

fetchMock.enableMocks();

describe("getShortClothes", () => {
    let dbWrapper: DBWrapper;

    beforeEach(() => {
        fetchMock.resetMocks();
        dbWrapper = new DBWrapper;
    });

    it("shouldn't return short clothes when token has not enough permissions", async () => {
        const fakeResponse = {"message": "Bad permissions"};
        const response = await dbWrapper.getShortClothes("miaou");

        expect(response.message).toBe(fakeResponse.message);
    });

    it("should return short clothes when token has enough permissions", async () => {
        const fakeResponse = {"message": "Success"};
        const login = "etienne.roussel@soul-connection.fr";
        const password = "kaguyaSamaL0VEIsWar2015";

        const token = await dbWrapper.loginClient(login, password);

        if (!token.var)
            return;

        const response = await dbWrapper.getShortClothes(token.var);

        expect(response.message).toBe(fakeResponse.message);
    });
});
