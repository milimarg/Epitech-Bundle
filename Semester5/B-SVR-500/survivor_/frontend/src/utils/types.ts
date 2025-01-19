export interface PaymentHistory {
  customer_id: number;
  id: number;
  date: string;
  payment_method: string;
  amount: number;
  comment: string;
}

export interface Clothe {
  customer_id: number;
  id: number;
  type: string;
  source: string | null;
};

export interface ShortCustomer {
  id: number;
  email: string;
  name: string;
  surname: string;
}

export type ZodiacSign = 'Aries' | 'Taurus' | 'Gemini' | 'Cancer' | 'Leo' | 'Virgo' | 'Libra' | 'Scorpio' | 'Sagittarius' | 'Capricorn' | 'Aquarius' | 'Pisces';

export interface Customer {
  id: number;
  email: string;
  name: string;
  surname: string;
  birth_date: string;
  gender: string;
  description: string;
  astrological_sign: ZodiacSign;
  phone_number: string;
  address: string;
  image: string | null;
}

export interface ShortEmployee {
  id: number;
  email: string;
  name: string;
  surname: string;
}

export interface Employee {
  id: number,
  email: string,
  name: string,
  surname: string,
  birth_date: string,
  gender: string,
  work: string,
  image: string | null,
  unix_time: number,
  assigned_customers: number[]
}

export interface ShortEncounter {
  id: number;
  customer_id: number;
  date: string;
  rating: number;
}

export interface Encounter {
  id: number;
  customer_id: number;
  date: string;
  rating: number;
  comment: string;
  source: string;
}

export interface Comment {
  id: number,
  customer_id: number,
  event_id: number,
  message: string
}

export interface Event {
  id: number;
  name: string;
  date: string;
  max_participants: number;
  location_x: string;
  location_y: string;
  type: string;
  employee_id: number;
  location_name: string;
  id_subscribed: number[];
  id_waiting: number[];
  status: 'upcoming' | 'passed' | 'canceled';
}

export interface Tip {
  id: number;
  title: string;
  tip: string;
}

export interface Response<T> {
  type: number,
  message: string
  var?: T,
}

export interface ErrorFetch {
  type: number,
  message: string
}

export interface TokenValue {
  id: number,
  email: string,
  name: string,
  surname: string,
  permission: 'COACH' | 'ADMIN' | 'CUSTOMER';
}
