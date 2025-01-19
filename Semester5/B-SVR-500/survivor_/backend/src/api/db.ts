import * as Types from "./types";
import { Customer, PrismaClient } from '@prisma/client';
import TokenClient from "./hash";
import { getUnixTime } from "../utils/unixTime";

type RespDB<T> = Promise<Types.Response<T>>;
const prisma = new PrismaClient();
const hash = new TokenClient();

export default class DBWrapper {

  // ! CHECK PERM
  async checkPermission(token: string, check: string[]): Promise<boolean> {
    const unhash: Types.TokenValue = hash.unhashValue<Types.TokenValue>(token);
    if (!unhash)
      return false;
    const credentials = await prisma.credential.findMany({
     where: {
       email: unhash.email,
     },
    });
    const value = {
      id: unhash.id,
      email: unhash.email,
      permission: unhash.permission
    }
    for (const credential of credentials) {
      const unhashTmp: Types.TokenValue = hash.unhashValue<Types.TokenValue>(credential.token);
      const valueTmp = {
        id: unhashTmp.id,
        email: unhashTmp.email,
        permission: unhashTmp.permission
      }
      if (JSON.stringify(value) === JSON.stringify(valueTmp))
        return (check.includes(value.permission))
    }
    return false;
  }

  async createCredentials(info: Types.TokenValue, password: string) : RespDB<string>{
    const credential = await prisma.credential.findUnique({
      where: {
        email: info.email
      },
    });
    if (credential) {
      await prisma.credential.delete({
        where: {
          email: info.email
        },
      });
    }
    const token = hash.hashValue<Types.TokenValue>(info);
    const value = {
      email: info.email,
      password: hash.hashValue<Types.Password>({
        password: password
      }),
      token: token
    }
    await prisma.credential.create({
      data: value
    })
    return {
      type: 200,
      message: "Success",
      var: token
    }
  }

  // ! DELETE
  async deleteCustomer(token: string, clientId: number): RespDB<null> {
    const perm = await this.checkPermission(token, ["ADMIN"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
    const customerTmp = await prisma.customer.findUnique({
      where: {
        id: clientId
      },
    });
    if (!customerTmp)
      return {
        type: 404,
        message: "Customers doesn't exist"
      };
    const customer = prisma.customer.delete({
      where: {
        id: clientId
      },
    });
    if (!customer)
      return {
        type: 500,
        message: "Failed to delete Customer"
      }
    return {
      type: 200,
      message: "Success"
    }
  }

  async deleteEmployee(token: string, clientId: number): RespDB<null>  {
    const perm = await this.checkPermission(token, ["ADMIN"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
    };
    const employeeTmp = await prisma.employee.findUnique({
      where: {
        id: clientId
      },
    });
    if (!employeeTmp)
      return {
        type: 404,
        message: "Customers doesn't exist"
      };
    const employee = await prisma.employee.delete({
      where: {
        id: clientId
      },
    });
    if (!employee)
      return {
        type: 500,
        message: "Failed to delete Employee"
      }
    return {
      type: 200,
      message: "Success"
    };
  }

  // ! GET
  async getCustomerImage(token: string, clientId: number): RespDB<string | null> {
    const perm = await this.checkPermission(token, ["ADMIN", "COACH", "CUSTOMER"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
    const customer = await prisma.customer.findUnique({
      where: {
        id: clientId,
      },
    });
    if (!customer)
      return {
        type: 404,
        message: "Customers doesn't exist"
      };
    return {
      type: 200,
      message: "Success",
      var: customer.image
    };
  }

  async getCustomerPayments(token: string, clientId: number): RespDB<Types.PaymentHistory[]> {
    const perm = await this.checkPermission(token, ["ADMIN", "COACH", "CUSTOMER"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
    const customer = await prisma.customer.findUnique({
      where: {
        id: clientId
      }
    })
    if (!customer)
      return {
        type: 404,
        message: "Customers doesn't exist"
      };
    const payments = await prisma.payment.findMany({
      where: {
        customer_id: clientId
      },
    });
    return {
      type: 200,
      message: "Success",
      var: payments
    };
  }

  async getPayments(token: string): RespDB<Types.PaymentHistory[]> {
    const perm = await this.checkPermission(token, ["ADMIN", "COACH"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
    const payments = await prisma.payment.findMany();
    return {
      type: 200,
      message: "Success",
      var: payments
    };
  }

  async getClothes(token: string): RespDB<Types.Clothe[]> {
    const perm = await this.checkPermission(token, ["ADMIN", "COACH"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
    const clothes = await prisma.clothe.findMany();
    return {
      type: 200,
      message: "Success",
      var: clothes
    };
  }

  async getShortClothes(token: string): RespDB<Types.ShortClothe[]> {
    const perm = await this.checkPermission(token, ["ADMIN", "COACH"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
    const clothes = await prisma.clothe.findMany();
    const shortClothes = clothes.map((clothe) => {
      return {
        customer_id: clothe.customer_id,
        id: clothe.id,
        type: clothe.type
      };
    });
    return {
      type: 200,
      message: "Success",
      var: shortClothes
    };
  }

  async getClotheById(token: string, clotheId: number): RespDB<Types.Clothe> {
    const perm = await this.checkPermission(token, ["ADMIN", "COACH"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
    const clothe = await prisma.clothe.findUnique({
      where: {
        id: clotheId,
      },
    });
    if (!clothe)
      return {
        type: 404,
        message: "Clothe doesn't exist"
      };
    return {
      type: 200,
      message: "Success",
      var: clothe
    };
  }

  async getClotheByCustomer(token: string, customerId: number): RespDB<Types.Clothe[]> {
    const perm = await this.checkPermission(token, ["ADMIN", "COACH"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
      const customer = prisma.customer.findUnique({
        where: {
          id: customerId
        }
      })
    if (!customer)
      return {
        type: 404,
        message: "Customers doesn't exist"
      };
    const clothes = await prisma.clothe.findMany({
      where: {
          customer_id: customerId,
      },
    });
    return {
      type: 200,
      message: "Success",
      var: clothes
    }
  }

  async getClotheTypeByCustomer(token: string, customerId: number, clotheType: string): RespDB<Types.Clothe[]> {
    const perm = await this.checkPermission(token, ["ADMIN", "COACH"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
    const customer = prisma.customer.findUnique({
      where: {
        id: customerId
      }
    })
    if (!customer)
      return {
        type: 404,
        message: "Customers doesn't exist"
      };
    const clothes = await prisma.clothe.findMany({
      where: {
        customer_id: customerId,
        type: clotheType
      },
    });
    return {
      type: 200,
      message: "Success",
      var: clothes.map((clothe) => { return clothe; })
    }
  }

  async getCustomerClothes(token: string, clientId: number): RespDB<Types.Clothe[]> {
    const perm = await this.checkPermission(token, ["ADMIN", "COACH", "CUSTOMER"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
    const customer = prisma.customer.findUnique({
      where: {
        id: clientId
      }
    })
    if (!customer)
      return {
        type: 404,
        message: "Customers doesn't exist"
      };
    const clothes = await prisma.clothe.findMany({
      where: {
        customer_id: clientId
      },
    });
    return {
      type: 200,
      message: "Success",
      var: clothes
    }
  }

  async getCustomerById(token: string, clientId: number): RespDB<Types.Customer> {
    const perm = await this.checkPermission(token, ["ADMIN", "COACH", "CUSTOMER"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
    const customer = await prisma.customer.findUnique({
      where: {
        id: clientId
      },
    });
    if (!customer)
      return {
        type: 404,
        message: "Customer doesn't exist"
      }
    return {
      type: 200,
      message: "Success",
      var: customer
    }
  }

  async getShortCustomers(token: string): RespDB<Types.ShortCustomer[]> {
    const perm = await this.checkPermission(token, ["ADMIN", "COACH"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
    const customers = await prisma.customer.findMany();
    const shortCustomers = customers.map((customer) => {
      return {
        id: customer.id,
        email: customer.email,
        name: customer.name,
        surname: customer.surname
      }
    })
    return {
      type: 200,
      message: "Success",
      var: shortCustomers
    }
  }

  async getCustomers(token: string): RespDB<Types.Customer[]> {
    const perm = await this.checkPermission(token, ["ADMIN", "COACH", "CUSTOMER"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
    const customers = await prisma.customer.findMany();
    return {
      type: 200,
      message: "Success",
      var: customers
    };
  }

  async getShortCustomerMe(token: string): RespDB<Types.ShortCustomer> {

    const unhash: Types.TokenValue = hash.unhashValue<Types.TokenValue>(token);
    if (!unhash)
      return {
        type: 401,
        message: "Invalid Token"
      };
    const shortCustomer = await prisma.customer.findUnique({
      where : {
        email: unhash.email
      }
    });
    if (!shortCustomer)
      return {
        type: 404,
        message: "Customer doesn't exist"
      }

    return {
      type: 200,
      message: "Success",
      var: {
        id: shortCustomer.id,
        email: shortCustomer.email,
        name: shortCustomer.name,
        surname: shortCustomer.surname
      }
    }
  }

  async getCustomerMe(token: string): RespDB<Types.Customer> {
    const unhash: Types.TokenValue = hash.unhashValue<Types.TokenValue>(token);
    if (!unhash)
      return {
        type: 401,
        message: "Invalid Token"
      };
    const customer = await prisma.customer.findUnique({
      where : {
        email: unhash.email
      }
    });
    if (!customer)
      return {
        type: 404,
        message: "Customer doesn't exist"
      }
    return {
      type: 200,
      message: "Success",
      var: customer
    };
  }

  async getEmployee(token: string, clientId: number): RespDB<Types.Employee> {
    const perm = await this.checkPermission(token, ["ADMIN"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
    const employee = await prisma.employee.findUnique({
      where: {
        id: clientId,
      },
    });
    if (!employee)
      return {
        type: 404,
        message: "Employee doesn't exist"
      }
    return {
      type: 200,
      message: "Success",
      var: employee
    }
  }

  async getEmployeeImage(token: string, clientId: number): RespDB<string | null> {
    const perm = await this.checkPermission(token, ["ADMIN"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
    const employee = await prisma.employee.findUnique({
      where: {
        id: clientId,
      },
    });
    if (!employee)
      return {
        type: 404,
        message: "Employee doesn't exist"
      }
    return {
      type: 200,
      message: "Success",
      var: employee.image
    }
  }

  async getShortEmployees(token: string): RespDB<Types.ShortEmployee[]> {
    const perm = await this.checkPermission(token, ["ADMIN"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
    const employees = await prisma.employee.findMany();
    const shortEmployees = employees.map((employee) => {
      return {
        id: employee.id,
        email: employee.email,
        name: employee.name,
        surname: employee.surname
      };
    });
    return {
      type: 200,
      message: "Success",
      var: shortEmployees
    }
  };

  async getEmployees(token: string): RespDB<Types.Employee[]> {
    const perm = await this.checkPermission(token, ["ADMIN"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
    const employees = await prisma.employee.findMany();
    return {
      type: 200,
      message: "Success",
      var: employees
    }
  };

  async getShortEmployeeMe(token: string): RespDB<Types.ShortEmployee> {
    const unhash: Types.TokenValue = hash.unhashValue<Types.TokenValue>(token);
    if (!unhash)
      return {
        type: 401,
        message: "Invalid Token"
      };
    const shortEmployee = await prisma.employee.findUnique({
      where : {
        email: unhash.email
      }
    });
    if (!shortEmployee)
      return {
        type: 404,
        message: "Employee doesn't exist"
      }
    return {
      type: 200,
      message: "Success",
      var: {
        id: shortEmployee.id,
        email: shortEmployee.email,
        name: shortEmployee.name,
        surname: shortEmployee.surname
      }
    }
  };

  async getEmployeeMe(token: string): RespDB<Types.Employee> {
    const unhash: Types.TokenValue = hash.unhashValue<Types.TokenValue>(token);
    if (!unhash)
      return {
        type: 401,
        message: "Invalid Token"
      };
    const employee = await prisma.employee.findUnique({
      where : {
        email: unhash.email
      }
    });
    if (!employee)
      return {
        type: 404,
        message: "Employee doesn't exist"
      }
    return {
      type: 200,
      message: "Success",
      var: employee
    }
  };

  async getTips(token: string): RespDB<Types.Tip[]> {
    const perm = await this.checkPermission(token, ["ADMIN", "COACH"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
    const tips = await prisma.tip.findMany();
    return {
      type: 200,
      message: "Success",
      var: tips
    }
  };

  async getEvents(token: string): RespDB<Types.Event[]> {
    const perm = await this.checkPermission(token, ["ADMIN", "COACH", "CUSTOMER"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
    const events = await prisma.event.findMany();
    return {
      type: 200,
      message: "Success",
      var: events
    }
  };

  async getEventById(token: string, eventId: number): RespDB<Types.Event> {
    const perm = await this.checkPermission(token, ["ADMIN", "COACH", "CUSTOMER"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
    const event = await prisma.event.findUnique({
      where: {
        id: eventId,
      },
    });
    if (!event)
      return {
        type: 404,
        message: "Event doesn't exist"
      }
    return {
      type: 200,
      message: "Success",
      var: event
    }
  }

  async getEventByIdComments(token: string, eventId: number): RespDB<Types.Comment[]> {
    const perm = await this.checkPermission(token, ["ADMIN", "COACH", "CUSTOMER"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
    const comments = await prisma.comment.findMany({
      where: {
        event_id: eventId,
      },
    });
    return {
      type: 200,
      message: "Success",
      var: comments
    }
  }

  async getEventByIdSubscribers(token: string, eventId: number): RespDB<Customer[]> {
    const perm = await this.checkPermission(token, ["ADMIN", "COACH", "CUSTOMER"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
    const event = await prisma.event.findUnique({
      where: {
        id: eventId,
      },
    });
    if (!event)
      return {
        type: 404,
        message: "Event doesn't exist"
      }
    const customers = await prisma.customer.findMany({
      where: {
        id: {
          in: event.id_subscribed,
        }
      }
    })
    if (!customers)
      return {
        type: 404,
        message: "No Customers fouund"
      }
    return {
      type: 200,
      message: "Success",
      var: customers
    }
  }

  async getEncounterById(token: string, encounterId: number): RespDB<Types.Encounter> {
    const perm = await this.checkPermission(token, ["ADMIN", "COACH"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
    const encounter = await prisma.encounter.findUnique({
      where: {
        id: encounterId,
      },
    });
    if (!encounter)
      return {
        type: 404,
        message: "Encounter doesn't exist"
      }
    return {
      type: 200,
      message: "Success",
      var: encounter
    }
  }

  async getEncounters(token: string): RespDB<Types.Encounter[]> {
    const perm = await this.checkPermission(token, ["ADMIN", "COACH"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
    const encounters = await prisma.encounter.findMany();
    return {
      type: 200,
      message: "Success",
      var: encounters
    }
  }

  async getEncounterByCustomer(token: string, customerId: number): RespDB<Types.Encounter[]> {
    const perm = await this.checkPermission(token, ["ADMIN", "COACH"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
    const encounters = await prisma.encounter.findMany({
      where: {
        customer_id: customerId
      }
    });
    return {
      type: 200,
      message: "Success",
      var: encounters
    }
  }

  // ! POST
  async updateClient(email: string)
  {
    const employee = await prisma.employee.findUnique({
      where : {
        email: email
      }
    });
    if (employee) {
      await prisma.employee.update({
        where: {
          email: email
        },
        data: {
          unix_time: getUnixTime()
        }
      });
      return;
    }
    const customer = await prisma.customer.findUnique({
      where : {
        email: email
      }
    });
    if (customer) {
      await prisma.customer.update({
        where: {
          email: email
        },
        data: {
          unix_time: getUnixTime()
        }
      });
      return;
    }
  }

  async loginClient(email: string, password: string): RespDB<string> {
    const credentials = await prisma.credential.findMany();
    if (!credentials)
      return {
        type: 401,
        message: "Email or Password is incorrect"
      }
    for (const credential of credentials) {
      if (!credential)
          continue;
      const decrypted = hash.unhashValue<Types.Password>(credential.password);
      if (credential.email == email && decrypted.password == password) {
        this.updateClient(credential.email);
        return {
          type: 200,
          message: "Success",
          var: credential.token
        }
      }
    }
    return {
      type: 401,
      message: "Email or Password is incorrect"
    }
  }

  async registerCustomer(customerInfo: Types.Customer, password: string): RespDB<string> {
    let customer = await prisma.customer.findUnique({
      where: {
        email: customerInfo.email
      },
    });
    if (customer)
      return {
        type: 409,
        message: "Customer already exist"
      }
    customer = await prisma.customer.create({
      data: {
        email: customerInfo.email,
        name: customerInfo.name,
        surname: customerInfo.surname,
        birth_date: customerInfo.birth_date,
        gender: customerInfo.gender,
        description: customerInfo.description,
        astrological_sign: customerInfo.astrological_sign,
        phone_number: customerInfo.phone_number,
        address: customerInfo.address,
        image: customerInfo.image,
        unix_time: getUnixTime()

      },
    });
    if (!customer)
      return {
        type: 500,
        message: "Failed to create Customer"
      }
    const info: Types.TokenValue = {
      id: customer.id,
      email: customer.email,
      permission: "CUSTOMER"
    }
    return this.createCredentials(info, password);
  }

  async registerEmployee(employeeInfo: Types.Employee, password: string, permission: string = "COACH"): RespDB<string> {
    let employee = await prisma.employee.findUnique({
      where: {
        email: employeeInfo.email
      },
    });
    if (employee)
      return {
        type: 409,
        message: "Employee already exist"
      }
    employee = await prisma.employee.create({
      data: {
        email: employeeInfo.email,
        name: employeeInfo.name,
        surname: employeeInfo.surname,
        birth_date: employeeInfo.birth_date,
        gender: employeeInfo.gender,
        work: employeeInfo.work,
        image: employeeInfo.image,
        unix_time: getUnixTime()
      },
    });
    if (!employee)
      return {
        type: 500,
        message: "Failed to create Employee"
      }
    const info: Types.TokenValue = {
      id: employee.id,
      email: employee.email,
      permission: permission
    }
    return this.createCredentials(info, password);
  }

  // ! PUT
  async addCommentEventById(token: string, commentInfo: Types.Comment): RespDB<null> {
    const perm = await this.checkPermission(token, ["ADMIN", "COACH", "CUSTOMER"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
    const comment = await prisma.comment.create({
      data: {
        customer_id: commentInfo.customer_id,
        event_id: commentInfo.event_id,
        message: commentInfo.message
      }
    });
    if (!comment)
      return {
        type: 500,
        message: "Failed to create Comment"
      }
    return {
      type: 200,
      message: "Success"
    }
  }

  async removeCommentEventById(token: string, commentId: number): RespDB<null> {
    const perm = await this.checkPermission(token, ["ADMIN"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
      const tmpComment = await prisma.comment.findUnique({
        where: {
          id: commentId
        },
      });
      if (!tmpComment)
        return {
          type: 404,
          message: "Comment doesn't exist"
        };
      const comment = await prisma.comment.delete({
        where: {
          id: commentId
        }
      });
      if (!comment)
        return {
          type: 500,
          message: "Failed to delete Comment"
        }
      return {
        type: 200,
        message: "Success"
      }
  }

  async subscribedToEvent(token: string, eventId: number, customerId: number): RespDB<null> {
    const perm = await this.checkPermission(token, ["ADMIN", "COACH", "CUSTOMER"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
    const event = await prisma.event.findUnique({
      where: {
        id: eventId
      }
    });
    if (!event)
      return {
        type: 404,
        message: "Event doesn't exist"
      }
    const customer = await prisma.customer.findUnique({
      where: {
        id: customerId
      },
    });
    if (!customer)
      return {
        type: 404,
        message: "Customers doesn't exist"
      };
    if (!event.id_subscribed.includes(customerId)) {
      if (event.id_subscribed.length < event.max_participants)
        event.id_subscribed.push(customerId);
      else
        event.id_waiting.push(customerId);
    }
    const eventTmp = await prisma.event.update({
      where: {
        id: eventId
      },
      data: event
    });
    if (!eventTmp)
      return {
        type: 500,
        message: "Failed to update Event"
      }
    return {
      type: 200,
      message: "Success"
    }
  }

  async unsubscribedToEvent(token: string, eventId: number, customerId: number): RespDB<null> {
    const perm = await this.checkPermission(token, ["ADMIN", "COACH", "CUSTOMER"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
    const event = await prisma.event.findUnique({
      where: {
        id: eventId
      }
    });
    if (!event)
      return {
        type: 404,
        message: "Event doesn't exist"
      }
    const customer = await prisma.customer.findUnique({
      where: {
        id: customerId
      },
    });
    if (!customer)
      return {
        type: 404,
        message: "Customers doesn't exist"
      };
    if (event.id_subscribed.includes(customerId)) {
      event.id_subscribed = event.id_subscribed.filter(item => item !== customerId);
      const waiting = event.id_waiting.pop();
      if (waiting)
        event.id_subscribed.push(waiting);
    }
    if (event.id_waiting.includes(customerId)) {
      event.id_waiting = event.id_waiting.filter(item => item !== customerId);
    }
    const eventTmp = await prisma.event.update({
      where: {
        id: eventId
      },
      data: event
    });
    if (!eventTmp)
      return {
        type: 500,
        message: "Failed to update Event"
      }
    return {
      type: 200,
      message: "Success"
    }
  }

  async setLimitEvent(token: string, eventId: number, limit: number): RespDB<null> {
    const perm = await this.checkPermission(token, ["ADMIN", "COACH"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
    const event = await prisma.event.findUnique({
      where: {
        id: eventId
      }
    });
    if (!event)
      return {
        type: 404,
        message: "Event doesn't exist"
      }

    if (event.id_subscribed.length > limit) {
        return {
          type: 500,
          message: "Too many subscribers to reduce the limit"
        }
    }
    while (event.id_subscribed.length < limit && event.id_waiting.length > 0) {
      const waiting = event.id_waiting.pop();
      if (waiting)
        event.id_subscribed.push(waiting);
    }
    const eventTmp = await prisma.event.update({
      where: {
        id: eventId
      },
      data: event
    });
    if (!eventTmp)
      return {
        type: 500,
        message: "Failed to update Event"
      }
    return {
      type: 200,
      message: "Success"
    }
  }

  async assignCustomers(token: string, id: number, assigned: number[]): RespDB<null> {
    const perm = await this.checkPermission(token, ["ADMIN"]);
    if (!perm)
      return {
        type: 403,
        message: "Bad permissions"
      };
    const employee = await prisma.employee.update({
      where: {
        id: id
      },
      data: {
        assigned_customers: assigned
      }
    });
    if (!employee)
      return {
        type: 500,
        message: "Failed to update Employee"
      }
    return {
      type: 200,
      message: "Success"
    }
  }
}
