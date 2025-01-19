import React from "react";
import { Gauge, gaugeClasses } from '@mui/x-charts/Gauge';
import './GaugeChart.css';

type Props = {
    width?: number;
    height?: number;
    startAngle: number;
    endAngle: number;
    value: number;
    chartName?: string;
    valueMax?: number;
};

type States = {
    //
};

class GaugeChart extends React.Component<Props, States> {
  render() {
    const {
      width = 500,
      height = 300,
      startAngle,
      endAngle,
      value,
      valueMax,
      chartName = '',
    } = this.props;

    return (
      <div className="gauge-container">
      <Gauge
        width={width}
        height={height}
        startAngle={startAngle}
        endAngle={endAngle}
        value={value}
        valueMax={valueMax}
        text={({ value, valueMax }) => `${value} / ${valueMax}`}
        sx={{
          [`& .${gaugeClasses.valueText}`]: {
            fontSize: 40,
            transform: 'translate(0px, 0px)',
          },
          [`& .${gaugeClasses.valueArc}`]: {
            fill: '#7284da',
          },
        }}
      >
      </Gauge>
      <h4>{chartName}</h4>
      </div>
    );
  }
};

export default GaugeChart;
