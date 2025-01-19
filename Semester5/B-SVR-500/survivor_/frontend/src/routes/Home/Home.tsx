import React from 'react';
import BackendRequester from '../../utils/backendRequester';
import BarChart from '../../components/BarChart/BarChart';
import Page from '../../components/Page/Page';
import CircularProgress from '@mui/material/CircularProgress';
import GaugeChart from "../../components/GaugeChart/GaugeChart";
import PieChartComponent from "../../components/PieChart/PieChart";
import './Home.css';

type Props = {
  //
};

type ChartData = {
  xAxisData: string[];
  seriesData: number[][];
  chartName: string;
};

type AgeData = {
  id: number;
  value: number;
  label: string;
};

type TopDonatersData = {
  axisData: string[];
  seriesData: number[][];
};

type Payment = {
  customer_id: number;
  amount: number;
};

type Customer = {
  id: number;
  name: string;
  surname: string;
};

type Clothe = {
  customer_id: number;
  type: string;
};

type State = {
  chartData: ChartData[];
  status: "loading" | "success" | "error";
  message?: string;
  averageRating: number;
  chartDataSec: ChartData[];
  ageData: AgeData[];
  axisAstroData: string[];
  seriesAstroData: number[][];
  axisGenderData: string[];
  seriesGenderData: number[][];
  clothesAverageData: { type: string; average: number }[];
  topDonatersData: TopDonatersData;
};

class Home extends React.Component<Props, State> {
  state: State = {
    chartData: [],
    status: "loading",
    averageRating: 0,
    chartDataSec: [],
    ageData: [],
    axisAstroData: [],
    seriesAstroData: [],
    axisGenderData: [],
    seriesGenderData: [],
    clothesAverageData: [],
    topDonatersData: {
      axisData: [],
      seriesData: []
    }
  };

  async loadChartData() {
    try {
      const [encountersData, eventsData] = await Promise.all([
        BackendRequester.fetchEncountersData(),
        BackendRequester.fetchEvents(),
      ]);
      if (BackendRequester.isFetchError(encountersData) || BackendRequester.isFetchError(eventsData)) {
        this.setState({ status: "error", message: "Error fetching encounters/events data: Invalid data" });
        return;
      }
      if (!Array.isArray(encountersData) || !Array.isArray(eventsData)) {
        this.setState({ status: "error", message: "Error fetching encounters/events data: Invalid data" });
        return;
      }
      const ratings = encountersData.map((item) => item.rating);
      const ratingCounts: { [key: number]: number } = {};
      ratings.forEach((rating: number) => {
        ratingCounts[rating] = (ratingCounts[rating] || 0) + 1;
      });
      const xAxisDataRatings = Object.keys(ratingCounts).map(key => key.toString());
      const seriesDataRatings = [Object.values(ratingCounts)];

      const sources = encountersData.map((item) => item.source);
      const sourceCounts: { [key: string]: number } = {};
      sources.forEach((source: string) => {
        sourceCounts[source] = (sourceCounts[source] || 0) + 1;
      });
      const xAxisDataSources = Object.keys(sourceCounts);
      const seriesDataSources = [Object.values(sourceCounts)];

      const eventsByMonth: { [key: string]: number } = {};
      eventsData.forEach((event) => {
        const month = event.date.slice(0, 7);
        eventsByMonth[month] = (eventsByMonth[month] || 0) + 1;
      });
      const xAxisDataEvents = Object.keys(eventsByMonth);
      const seriesDataEvents = [Object.values(eventsByMonth)];

      this.setState({
        chartData: [
          { xAxisData: xAxisDataRatings, seriesData: seriesDataRatings, chartName: 'Ratings' },
          { xAxisData: xAxisDataSources, seriesData: seriesDataSources, chartName: 'Sources' },
          { xAxisData: xAxisDataEvents, seriesData: seriesDataEvents, chartName: 'Events' },
          { xAxisData: xAxisDataSources, seriesData: seriesDataSources, chartName: 'Sources' },
        ], status: "success"
      });
    } catch (error) {
      this.setState({ status: "error", message: "Error fetching encounters/events data: Invalid data" });
    }
  }

  async loadRatingData() {
    try {
      const encountersData = await BackendRequester.fetchEncountersData();
      if (!Array.isArray(encountersData)) {
        console.error('Data is not an array');
        return;
      }
      const ratings = encountersData.map((item) => item.rating);
      const totalRatings = ratings.reduce((acc: number, rating: number) => acc + rating, 0);
      const averageRating = totalRatings / ratings.length;

      this.setState({
        averageRating,
      });
    } catch (error) {
      console.error('Failed to fetch data', error);
    }
  }
  async loadCustomerData() {
    try {
      const customersData = await BackendRequester.fetchCustomersData();
      if (BackendRequester.isFetchError(customersData)) {
        console.error('Failed to fetch customers data');
        return;
      }
      const currentYear = new Date().getFullYear();
      const astrologicalSigns: { [key: string]: number } = {
        Aries: 0,
        Taurus: 0,
        Gemini: 0,
        Cancer: 0,
        Leo: 0,
        Virgo: 0,
        Libra: 0,
        Scorpio: 0,
        Sagittarius: 0,
        Capricorn: 0,
        Aquarius: 0,
        Pisces: 0,
      };
      const genderCounts: { [key: string]: number } = {};
      const ageGroups: { [key: string]: number } = {
        '0-18': 0,
        '19-35': 0,
        '36-50': 0,
        '51-65': 0,
        '65+': 0,
      };

      if (!Array.isArray(customersData)) {
        console.error('Data is not an array');
        return;
      }
      customersData.forEach((customer) => {
        const birthYear = new Date(customer.birth_date).getFullYear();
        const sign = customer.astrological_sign;
        const gender = customer.gender;
        if (astrologicalSigns[sign] !== undefined) {
          astrologicalSigns[sign]++;
        }
        if (gender)
          genderCounts[gender] = (genderCounts[gender] || 0) + 1;
        const age = currentYear - birthYear;
        if (age <= 18) ageGroups['0-18']++;
        else if (age <= 35) ageGroups['19-35']++;
        else if (age <= 50) ageGroups['36-50']++;
        else if (age <= 65) ageGroups['51-65']++;
        else ageGroups['65+']++;
      });
      const totalCustomers = customersData.length;
      const ageData = Object.keys(ageGroups).map((key, index) => ({
        id: index,
        value: (ageGroups[key] / totalCustomers) * 100,
        label: key,
      }));
      const axisAstroData = Object.keys(astrologicalSigns);
      const seriesAstroData = Object.values(astrologicalSigns).map((count, index) => ({
        id: index,
        value: count,
        label: axisAstroData[index],
      }));
      const axisGenderData = Object.keys(genderCounts);
      const seriesGenderData = Object.values(genderCounts).map((count, index) => ({
        id: index,
        value: count,
        label: axisGenderData[index],
      }));
      this.setState({
        ageData,
        axisAstroData,
        seriesAstroData: [seriesAstroData.map(data => data.value)],
        axisGenderData,
        seriesGenderData: [seriesGenderData.map(data => data.value)]
      });
    } catch (error) {
      console.error('Failed to fetch data', error);
    }
  }
  async loadPaymentsData() {
    try {
      const paymentsData = await BackendRequester.fetchPaymentsData();
      if (BackendRequester.isFetchError(paymentsData)) {
        console.error('Failed to fetch payments data');
        return;
      }
      if (!Array.isArray(paymentsData)) {
        console.error('Data is not an array');
        return;
      }
      const customersData = await BackendRequester.fetchCustomersData();
      if (BackendRequester.isFetchError(customersData)) {
        console.error('Failed to fetch customers data');
        return;
      }
      const customers: Customer[] = customersData;

      const paymentsByCustomer: { [key: number]: number } = {};
      paymentsData.forEach((payment: Payment) => {
        const customerId = payment.customer_id;
        paymentsByCustomer[customerId] = (paymentsByCustomer[customerId] || 0) + payment.amount;
      });

      const customerNames: { [key: number]: string } = {};
      customersData.forEach((customer: Customer) => {
        customerNames[customer.id] = `${customer.name[0]}.${customer.surname}`;
      });

      const sortedCustomers = Object.entries(paymentsByCustomer)
        .map(([customerId, totalAmount]) => ({
          customerId: parseInt(customerId),
          totalAmount,
          customerName: customerNames[parseInt(customerId)],
        }))
        .sort((a, b) => b.totalAmount - a.totalAmount)
        .slice(0, 5);

      const axisData = sortedCustomers.map(customer => customer.customerName);
      const seriesData = sortedCustomers.map(customer => customer.totalAmount);

      this.setState({
        topDonatersData: {
          axisData,
          seriesData: [seriesData],
        },
      });
    } catch (error) {
      console.error('Failed to fetch data', error);
    }
  }
  async loadClothesAverageData() {
    try {
      const clothesData = await BackendRequester.fetchShortClothesData();
      if (BackendRequester.isFetchError(clothesData)) {
        console.error('Failed to fetch clothes data');
        return;
      }
      if (!Array.isArray(clothesData)) {
        console.error('Data is not an array');
        return;
      }

      const clothesCount: { [key: string]: number } = {};
      const customerCount: { [key: string]: number } = {};

      clothesData.forEach((clothe: Clothe) => {
        const customerId = clothe.customer_id;
        const type = clothe.type;
        if (clothesCount[type]) {
          clothesCount[type]++;
        } else {
          clothesCount[type] = 1;
        }
        if (customerCount[customerId]) {
          customerCount[customerId]++;
        } else {
          customerCount[customerId] = 1;
        }
      });

      const totalCustomers = Object.keys(customerCount).length;
      const clothesAverageData = Object.keys(clothesCount).map((type) => ({
        type,
        average: clothesCount[type] / totalCustomers,
      }));

      const orderedTypes = ['hat/cap', 'top', 'bottom', 'shoes'];
      clothesAverageData.sort((a, b) => orderedTypes.indexOf(a.type) - orderedTypes.indexOf(b.type));
      this.setState({ clothesAverageData });
    } catch (error) {
      console.error('Failed to fetch clothes data', error);
    }
  }

  componentDidMount() {
    this.loadChartData();
    this.loadRatingData();
    this.loadCustomerData();
    this.loadPaymentsData();
    this.loadClothesAverageData();
  }

  render() {
    const { chartData, status, message, averageRating, ageData, topDonatersData } = this.state;

    let renderElement: React.ReactNode;

    switch (status) {
      case "loading":
        renderElement =
          <div className={"loading-screen"}>
            <CircularProgress color="inherit" />
          </div>;
        break;
      case "error":
        renderElement =
        <div className={"error-message"}>
            <p>{message}</p>
        </div>;
        break;
      case "success":
        renderElement =
        <div className="home-container">
          <div className='home-chart-wrapper'>
              <BarChart
                axisData={chartData[0].xAxisData}
                seriesData={chartData[0].seriesData}
                chartName={chartData[0].chartName}
              />
          </div>
          <div className='home-chart-wrapper'>
            <BarChart
              axisData={chartData[1].xAxisData}
              seriesData={chartData[1].seriesData}
              chartName={chartData[1].chartName}
            />
          </div>
          <div className='home-chart-wrapper'>
            <BarChart
              axisData={chartData[2].xAxisData}
              seriesData={chartData[2].seriesData}
              chartName={chartData[2].chartName}
            />
          </div>
          <div className='home-chart-wrapper'>
            <GaugeChart
              startAngle={-100}
              endAngle={100}
              value={averageRating}
              valueMax={5}
              chartName="Rating average"
            />
          </div>
          <div className='home-chart-wrapper'>
            <BarChart
              axisData={this.state.axisAstroData}
              seriesData={this.state.seriesAstroData}
              layout="horizontal"
              chartName="Astrological stats"
            />
          </div>
          <div className='home-chart-wrapper'>
            <BarChart
              axisData={this.state.axisGenderData}
              seriesData={this.state.seriesGenderData}
              layout="horizontal"
              chartName="Gender"
            />
          </div>
          <div className='home-chart-wrapper'>
            <PieChartComponent
              serie={ageData}
              middleradius={50}
              chartName="Age"
            />
          </div>
          <div className='home-chart-wrapper'>
            <BarChart
              axisData={topDonatersData.axisData}
              seriesData={topDonatersData.seriesData}
              width={500}
              height={300}
              chartName="Top donaters"
            />
          </div>
          <div className='home-chart-wrapper'>
            <BarChart
              axisData={this.state.clothesAverageData.map(data => data.type)}
              seriesData={[this.state.clothesAverageData.map(data => data.average)]}
              layout="vertical"
              chartName="Clothes average"
            />
          </div>
        </div>
        break;
    }

    return (
      <Page pageTitle='Dashboard' pageSubtitle='Welcome!'>
        {renderElement}
      </Page>
    );
  }
}

export default Home;

