import React from "react";
import { PieChart } from '@mui/x-charts/PieChart';
import './PieChart.css';

type seriesData = {
  id: number;
  value: number;
  label: string;
};

type Props = {
  serie: seriesData[];
  middleradius?: number;
  width?: number;
  height?: number;
  chartName?: string;
};

type States = {
  //
};

class PieChartComponent extends React.Component<Props, States> {
  render() {
    const {
      serie,
      middleradius,
      width = 500,
      height = 300,
      chartName = '',
    } = this.props;

    return (
      <div className="piechart-container">
        <PieChart
          series={[
            {
              data: serie,
              innerRadius: middleradius,
            },
          ]}
          width={width}
          height={height}
        />
        <h4>{chartName}</h4>
      </div>
    );
  }
}

export default PieChartComponent;