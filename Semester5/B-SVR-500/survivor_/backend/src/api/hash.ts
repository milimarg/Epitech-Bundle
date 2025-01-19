import jwt from 'jsonwebtoken';
import * as Types from "./types";

const secretKey = process.env.SECRETKEY ?? '';

const header = {
  alg: "HS256",
  typ: "JWT"
};

export default class TokenClient {
  hashValue<T extends object>(value: T): string {
    return jwt.sign(value, secretKey, { header: header });
  }

  unhashValue<T>(password: string): T {
    const decoded = jwt.decode(password) as T;
    return decoded;
  }
}
