import dotenv from 'dotenv';
import * as Types from './types';
import { PrismaClient } from '@prisma/client';
import { Buffer } from "buffer";
import { writeFileSync } from "fs";

dotenv.config();

const token = process.env.TOKEN ?? '';
const prisma = new PrismaClient();

export default class APIWrapper {

  async login(email: string, password: string): Promise<string> {
    const loginUrl = 'https://soul-connection.fr/api/employees/login';
    const response = await fetch(loginUrl, {
      method: 'POST',
      headers: {
        'Accept': 'application/json',
        'X-Group-Authorization': token,
        'Content-Type': 'application/json'
      },
      body: JSON.stringify({
        email,
        password
      }),
    });

    if (!response.ok)
      throw new Error(`POST - Failed to login: ${response.status} ${response.statusText}`);

    const data = await response.json();
    return data.access_token;
  };

  private async getResponse(clientToken: string, root: string): Promise<Response> {
    const loginUrl = 'https://soul-connection.fr/api/' + root;
    const response = await fetch(loginUrl, {
      method: 'GET',
      headers: {
        'Accept': '*/*',
        'X-Group-Authorization': token,
        'Authorization': 'Bearer ' + clientToken,
        'Content-Type': 'application/json'
      },
    });

    if (!response.ok)
      throw new Error(`GET - Failed to fetch data: ${response.status} ${response.statusText}`);
    return response;
  }

  private async getImage(clientToken: string, root: string): Promise<string | null> {
    try {
      const response = await this.getResponse(clientToken, root);
      const arrayBuffer = await response.arrayBuffer();
      const buffer = Buffer.from(arrayBuffer);

      return buffer.toString('base64');
    } catch (error) {
      return null;
    }
  }

  private async getJson<T>(clientToken: string, root: string): Promise<T> {
    const response = await this.getResponse(clientToken, root);
    const data: T = await response.json();
    return data;
  };

  private async getCustomersAPI(clientToken: string): Promise<Types.ShortCustomer[]> {
    return this.getJson<Types.ShortCustomer[]>(clientToken, 'customers');
  }

  private async getClotheImageAPI(clientToken: string, clotheId: number): Promise<string | null> {
    return this.getImage(clientToken, 'clothes/' + clotheId + '/image');
  }

  private async getClothesAPI(clientToken: string, clientId: number): Promise<Types.Clothe[]> {
    return this.getJson<Types.Clothe[]>(clientToken, 'customers/' + clientId + '/clothes');
  }

  private async getPaymentsAPI(clientToken: string, clientId: number): Promise<Types.PaymentHistory[]> {
    return this.getJson<Types.PaymentHistory[]>(clientToken, 'customers/' + clientId + '/payments_history');
  }

  private async fetchClothesAPI(clientToken: string, clientId: number) {
    try {
      const clothes = await this.getClothesAPI(clientToken, clientId);
      for (const element of clothes) {
        try {
          const source = await this.getClotheImageAPI(clientToken, element.id);
          prisma.clothe.findUnique({
            where: {
              customer_id: clientId,
              id: element.id
            },
          }).then((existingEvent: Types.Clothe | null) => {
            if (!existingEvent) {
              prisma.clothe.create({
                data: {
                  id: element.id,
                  customer_id: clientId,
                  type: element.type,
                  source: source
                },
              }).then();
            }
          });
        } catch (error) {
          console.error('Fetch Clothes Error :', error);
          return;
        }
      }
    } catch (error) {
      console.error('Fetch Clothes Error :', error);
      return;
    }
  }

  private async fetchPaymentsAPI(clientToken: string, clientId: number) {
    try {
      const payments = await this.getPaymentsAPI(clientToken, clientId);
      for (const element of payments) {
        prisma.payment.findUnique({
          where: {
            customer_id: clientId,
            id: element.id,
          },
        }).then((existingEvent: Types.PaymentHistory | null) => {
          if (!existingEvent) {
            prisma.payment.create({
              data: {
                id: element.id,
                customer_id: clientId,
                date: element.date,
                payment_method: element.payment_method,
                amount: element.amount,
                comment: element.comment
              },
            }).then();
          }
        });
      }
    } catch (error) {
      console.error('Fetch Payments Error :', error);
      return;
    }
  }

  private async fetchCustomersAPI(clientToken: string) {
    try {
      const customers = await this.getCustomersAPI(clientToken);
      if (customers.length == 0) return;

      for (const element of customers) {
        try {
          const customer = await this.getJson<Types.Customer>(clientToken, 'customers/' + element.id);
          const image = await this.getImage(clientToken, 'customers/' + element.id + '/image');
          prisma.customer.findUnique({
            where: {
              email: customer.email
            },
          }).then((existingEvent: Types.Customer | null) => {
            if (!existingEvent) {
              prisma.customer.create({
                data: {
                  email: customer.email,
                  name: customer.name,
                  surname: customer.surname,
                  birth_date: customer.birth_date,
                  gender: customer.gender,
                  description: customer.description,
                  astrological_sign: customer.astrological_sign,
                  phone_number: customer.phone_number,
                  address: customer.address,
                  image: image,
                  unix_time: 0
                },
              }).then();
            }
          });
          this.fetchClothesAPI(clientToken, customer.id);
          this.fetchPaymentsAPI(clientToken, customer.id);
        } catch (error) {
          console.error('Fetch Customers Error :', error);
          return;
        }
      }
    } catch (error) {
      console.error('Fetch Customers Error :', error);
    }
  }

  private async getEmployeesAPI(clientToken: string): Promise<Types.ShortEmployee[]> {
    return await this.getJson<Types.ShortEmployee[]>(clientToken, 'employees');
  };

  private async fetchEmployeesAPI(clientToken: string) {
    try {
      const employees = await this.getEmployeesAPI(clientToken);
      if (employees.length == 0) return;

      for (const element of employees) {
        try {
          const employee = await this.getJson<Types.Employee>(clientToken, 'employees/' + element.id);
          const image = await this.getImage(clientToken, 'employees/' + element.id + '/image');
          prisma.employee.findUnique({
            where: {
              email: employee.email
            },
          }).then((existingEvent: Types.Employee | null) => {
            if (!existingEvent) {
              prisma.employee.create({
                data: {
                  email: employee.email,
                  name: employee.name,
                  surname: employee.surname,
                  birth_date: employee.birth_date,
                  gender: employee.gender,
                  work: employee.work,
                  image: image,
                  unix_time: 0
                },
              }).then();
            }
          });
        } catch (error) {
        console.error('Fetch Employees Error :', error);
        }
      }
    } catch (error) {
      console.error('Fetch Employees Error :', error);
    }
  }
  private async getEncountersAPI(clientToken: string): Promise<Types.ShortEncounter[]> {
    return this.getJson<Types.ShortEncounter[]>(clientToken, 'encounters');
  };

  private async fetchEncountersAPI(clientToken: string) {
    try {
      const encounters = await this.getEncountersAPI(clientToken);
      if (encounters.length == 0) return;

      for (const element of encounters) {
        try {
          const encounter = await this.getJson<Types.Encounter>(clientToken, 'encounters/' + element.id);
          prisma.encounter.findUnique({
            where: {
              id: element.id
            },
          }).then((existingEvent: Types.Encounter | null) => {
            if (!existingEvent) {
              prisma.encounter.create({
                data: {
                  id: encounter.id,
                  customer_id: encounter.customer_id,
                  date: encounter.date,
                  rating: encounter.rating,
                  comment: encounter.comment,
                  source: encounter.source
                },
              }).then();
            }
          });
        } catch (error) {
          console.error('Fetch Encounters Error :', error);
          return;
        }
      }
    } catch (error) {
      console.error('Fetch Encounters Error :', error);
      return;
    }
  }

  private async getTipsAPI(clientToken: string): Promise<Types.Tip[]> {
    return this.getJson<Types.Tip[]>(clientToken, 'tips');
  };

  private async fetchTipsAPI(clientToken: string) {
    try {
      const tips: Types.Tip[] = await this.getTipsAPI(clientToken);
      if (tips.length == 0) return;

      tips.forEach(element => {
        prisma.tip.findUnique({
          where: {
            id: element.id
          },
        }).then((existingEvent: Types.Tip | null) => {
          if (!existingEvent) {
            prisma.tip.create({
              data: {
                id: element.id,
                title: element.title,
                tip: element.tip
              },
            }).then();
          }
        });
      });
    } catch (error) {
      console.error('Fetch Tips Error :', error);
      return;
    }
  }

  private async getEventsAPI(clientToken: string): Promise<Types.Event[]> {
    return this.getJson<Types.Event[]>(clientToken, 'events');
  };

  private async fetchEventsAPI(clientToken: string) {
    const events: Types.Event[] = await this.getEventsAPI(clientToken);
    if (events.length == 0) return [];

    for (const element of events) {
      try {
        const event: Types.Event = await this.getJson<Types.Event>(clientToken, 'events/' + element.id);
        prisma.event.findUnique({
          where: {
            id: event.id
          },
        }).then((existingEvent: Types.Event | null) => {
          if (!existingEvent) {
            prisma.event.create({
              data: {
                id: event.id,
                name: event.name,
                date: event.date,
                max_participants: event.max_participants,
                location_x: event.location_x,
                location_y: event.location_y,
                type: event.type,
                employee_id: event.employee_id,
                location_name: event.location_name,
                id_subscribed: event.id_subscribed,
                id_waiting: event.id_waiting,
                status: "upcoming"
              },
            }).then();
          }
        });
      } catch (error) {
        console.error('Fetch Tips Events :', error);
        return;
      }
    };
  }

  fetchLocalData(clientToken: string) {
    this.fetchCustomersAPI(clientToken);
    this.fetchEmployeesAPI(clientToken);
    this.fetchEncountersAPI(clientToken);
    this.fetchTipsAPI(clientToken);
    this.fetchEventsAPI(clientToken);
  }
}
