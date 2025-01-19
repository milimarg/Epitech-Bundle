import React from "react";
import { LineChart } from "@mui/x-charts/LineChart";
import "./LineChart.css";
import { AxisConfig, ChartsXAxisProps, LineSeriesType } from "@mui/x-charts";
import { AxisScaleConfig, DatasetType } from "@mui/x-charts/internals";

type Props = {
  // axisValues: string[];
  // valueFormatter?: (value: string) => string;
  // series: {
    //   id: string;
    //   label: string;
    //   dataKey: string;
    //   stack?: string;
    //   showMark?: boolean;
    //   data: number[];
    // }[];

  // xAxis: AxisConfig<keyof AxisScaleConfig, any, ChartsXAxisProps>[];
  xAxis: AxisConfig[];
  series: LineSeriesType[];
  dataset: DatasetType;

  width?: number;
  height?: number;
  chartName?: string;
};

class LineChartComponent extends React.Component<Props> {
  static defaultProps = {
    axisValues: [],
    series: [],
    width: 500,
    height: 300,
  };

  render() {
    // const { axisValues, valueFormatter, series, dataset, width, height, chartName = '' } = this.props;
    const { xAxis, series, dataset, width, height, chartName = '' } = this.props;

    // const dataset = series.map(s => ({
    //   id: s.id,
    //   label: s.label,
    //   dataKey: s.dataKey,
    //   stack: s.stack,
    //   showMark: s.showMark ? s.showMark.toString() : undefined,
    //   data: s.data.toString(),
    // }));

    return (
      <div className="line-container">
        {/* <LineChart
          dataset={dataset}
          xAxis={xAxis}
          // xAxis={[{ valueFormatter , data: axisValues }]}
          series={series}
          // series={series.map(s => ({
          //   id: s.id,
          //   label: s.label,
          //   dataKey: s.dataKey,
          //   stack: s.stack,
          //   showMark: s.showMark,
          //   data: s.data,
          // }))}
          width={width}
          height={height}
        /> */}
        <h4>{chartName}</h4>
      </div>
    );
  }
}

export default LineChartComponent;
