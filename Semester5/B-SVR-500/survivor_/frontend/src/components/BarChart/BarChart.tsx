import React from "react";
import { BarChart as MuiBar } from '@mui/x-charts/BarChart';
import './BarChart.css';

type Props = {
  axisData?: string[];
  seriesData: number[][];
  width?: number;
  height?: number;
  layout?: 'horizontal' | 'vertical';
  chartName?: string;
};

type State = {
    //
};

class BarChart extends React.Component<Props, State> {
  render() {
    const {
      axisData,
      seriesData,
      width = 500,
      height = 300,
      layout = 'vertical',
      chartName = '',
    } = this.props;

    return (
      <div className="barchart-container">
        <MuiBar
          xAxis={layout === 'vertical' ? [{ scaleType: 'band' as const, data: axisData }] : undefined}
          yAxis={layout === 'horizontal' ? [{ scaleType: 'band' as const, data: axisData }] : undefined}
          series={seriesData.map(data => ({ data }))}
          width={width}
          height={height}
          layout={layout}
          colors={['#7284da']}
        />
        <h4>{chartName}</h4>
      </div>
    );
  }
};

export default BarChart;
