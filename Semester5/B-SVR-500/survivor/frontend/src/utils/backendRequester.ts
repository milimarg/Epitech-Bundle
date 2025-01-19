import axios from "axios";
import { Clothe, Employee, Customer, Response, Tip, PaymentHistory, Encounter, Comment, Event, ErrorFetch } from "./types";

class BackendRequester {
  static async fetchData<T>(fullUrl: string, body?: object, method: 'get' | 'post' | 'put' = 'get'): Promise<T | ErrorFetch> {
    try {
      let url: string = `${process.env.REACT_APP_API_URL}${fullUrl}`;
      if (method === 'get' || method === 'put') {
        const token = localStorage.getItem('authToken');
        body = { ...body, token };
      }
      if (method === 'get') {
        const queryParams = new URLSearchParams(body as Record<string, string>).toString();
        url = `${process.env.REACT_APP_API_URL}${fullUrl}?${queryParams}`;
      }

      const response = await axios({
        method,
        url,
        data: body,
        headers: {
          'Content-Type': 'application/json',
        }
      });

      const responseData: Response<T> = response.data;

      if (responseData.type !== 200)
        console.error(responseData.message);
      if (responseData.var)
        return responseData.var;
      else
        return {
          type: responseData.type,
          message: responseData.message
        }
    } catch (error) {
      console.error('Error fetching data:', error);
      return {
        type: 500,
        message: 'Error fetching data'
      }
    }
  }

  static isFetchError(error: any): error is ErrorFetch {
    return error && typeof error.type === 'number' && typeof error.message === 'string';
  }

  static async login(email: string, password: string): Promise<string | ErrorFetch> {
    const url = `/login`;
    const body = { email, password };
    return await this.fetchData<string>(url, body, 'post');
  }

  static async fetchCustomersData(): Promise<Customer[] | ErrorFetch> {
    const url = `/customers`;
    return this.fetchData<Customer[]>(url);
  }

  static async fetchShortCustomersData(): Promise<Customer[] | ErrorFetch> {
    const url = `/customersShort`;
    return this.fetchData<Customer[]>(url);
  }

  static async fetchEncountersData(): Promise<Encounter[] | ErrorFetch> {
    const url = `/encounters`;
    const token = localStorage.getItem('authToken');
    const body = { token };
    return this.fetchData<Encounter[]>(url, body);
  }

  static async fetchCoachesData(): Promise<Employee[] | ErrorFetch> {
    const url = `/employees`;
    return this.fetchData<Employee[]>(url);
  }

  static async fetchCustomerById(id: number): Promise<Customer | ErrorFetch> {
    const url = `/customers/${id}`;
    return this.fetchData<Customer>(url);
  }

  static async fetchCoachById(id: number): Promise<Customer | ErrorFetch> {
    const url = `/employees/${id}`;
    return this.fetchData<Customer>(url);
  }

  static async fetchClothesData(): Promise<Clothe[] | ErrorFetch> {
    const url = `/clothes`;
    return this.fetchData<Clothe[]>(url);
  }

  static async fetchShortClothesData(): Promise<Clothe[] | ErrorFetch> {
    const url = `/clothesshort`;
    return this.fetchData<Clothe[]>(url);
  }

  static async fetchClothById(id: number): Promise<Clothe | ErrorFetch> {
    const url = `/clothes/${id}`;
    return this.fetchData<Clothe>(url);
  }

  static async fetchClothByCustomerId(id: number): Promise<Clothe[] | ErrorFetch> {
    const url = `/customers/${id}/clothes`;
    return this.fetchData<Clothe[]>(url);
  }

  static async fetchSpecificClothByCustomerId(id: number, clothType: "hat/cap" | "top" | "bottom" | "shoes"): Promise<Clothe[] | ErrorFetch> {
    const url = `/customers/${id}/clothes/${clothType}`;
    return this.fetchData<Clothe[]>(url);
  }

  static async fetchTips(): Promise<Tip[] | ErrorFetch> {
    const url = `/tips`;
    return this.fetchData<Tip[]>(url);
  }

  static async fetchCustomerPaymentsData(id: number): Promise<PaymentHistory[] | ErrorFetch> {
    const url = `/customers/${id}/payments_history`;
    return this.fetchData<PaymentHistory[]>(url);
  }

  static async fetchCustomerMeetingsData(id: number): Promise<Encounter[] | ErrorFetch> {
    const url = `/encounters/customer/${id}`;
    return this.fetchData<Encounter[]>(url);
  }

  static async fetchEvents(): Promise<Event[] | ErrorFetch> {
    const url = `/events`;
    return this.fetchData<Event[]>(url);
  }

  static async fetchPaymentsData(): Promise<PaymentHistory[] | ErrorFetch> {
    const url = `/payments_history`;
    return this.fetchData<PaymentHistory[]>(url);
  }

  static async updateAssignedCustomers(id: number, assigned: number[]): Promise<void | ErrorFetch> {
    const url = `/employees/${id}/assignCustomers`;
    return this.fetchData<void>(url, {"assigned": assigned}, 'put');
  }

  static async addCommentToEvent(customer_id: number, event_id: number, message: string): Promise<void | ErrorFetch> {
    const url = `/events/addcomment`;
    const comment = {
      customer_id,
      event_id,
      message
    }
    return this.fetchData<void>(url, { comment }, 'put');
  }

  static async removeCommentFromEvent(commentId: number): Promise<void | ErrorFetch> {
    const url = `/events/removecomment`;
    return this.fetchData<void>(url, { commentId }, 'put');
  }

  static async subscribedToEvent(eventId: number, customerId: number): Promise<void | ErrorFetch> {
    const url = `/events/${eventId}/subscribed`;
    return this.fetchData<void>(url, { customerId }, 'put');
  }

  static async unsubscribedFromEvent(eventId: number, customerId: number): Promise<void | ErrorFetch> {
    const url = `/events/${eventId}/unsubscribed`;
    return this.fetchData<void>(url, { customerId }, 'put');
  }

  static async fetchEventComments(eventId: number): Promise<Comment[] | ErrorFetch> {
    const url = `/events/${eventId}/comments`;
    return this.fetchData<Comment[]>(url);
  }

  static async fetchEventSubscribers(eventId: number): Promise<Customer[] | ErrorFetch> {
    const url = `/events/${eventId}/subscribers`;
    return this.fetchData<Customer[]>(url);
  }

  static async setLimitEvent(eventId: number, limit: number): Promise<void | ErrorFetch> {
    const url = `/events/${eventId}/setlimit`;
    return this.fetchData<void>(url, { limit }, 'put');
  }

  static async fetchCustomerInfoMe(): Promise<Customer | ErrorFetch> {
    const url = `/customers/me`;
    return this.fetchData<Customer>(url);
  }
}

export default BackendRequester;
