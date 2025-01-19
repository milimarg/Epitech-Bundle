import React from "react";
import { Table, TableBody, TableCell, TableHead, TableRow, Checkbox } from "@mui/material";
import SearchBar from '../SearchBar/SearchBar'
import "./Table.css";

type SearchValues = {
  placeholder?: string;
  debounceTime?: number;
  suggestions?: string[];
  searchDataKeys?: string[];
};

type Props = {
  tableName?: string;
  columns: string[];
  data: { [key: string]: any }[];
  showCheckboxes?: boolean;
  handleCheckboxChange?: (event: React.ChangeEvent<HTMLInputElement>, index: number) => void;
  searchValues?: SearchValues;
};

type State = {
  filteredData: { [key: string]: any }[];
  query: string;
};

class TableComponent extends React.Component<Props, State> {
  state: State = {
    filteredData: this.props.data,
    query: '',
  };

  handleCheckboxChange = (event: React.ChangeEvent<HTMLInputElement>, index: number) => {
    console.log(`Checkbox at row ${index} changed: ${event.target.checked}`);
  };

  handleSearchChange = (query: string) => {
    const { data, searchValues } = this.props;
    const filteredData = data.filter((row) => {
      return searchValues?.searchDataKeys?.some((column) => {
        const cellValue = row[column]?.toString().toLowerCase();
        return cellValue?.includes(query.toLowerCase());
      });
    });

    this.setState({ filteredData, query });
  };

  render() {
    const { tableName, columns, showCheckboxes, searchValues } = this.props;
    const { filteredData } = this.state;

    return (
      <div className="table">
        {tableName && <h4>{tableName}</h4>}

        {searchValues && (
          <SearchBar
            onSearch={(query) => this.handleSearchChange(query)}
            onChange={this.handleSearchChange}
            placeholder={searchValues.placeholder || "Search..."}
            debounceTime={searchValues.debounceTime || 300}
            suggestionProps={{
              list: searchValues.suggestions || [],
              alwaysVisible: false,
            }}
          />
        )}

        <Table className="table-content">
          <TableHead>
            <TableRow>
              {showCheckboxes && <TableCell padding="checkbox"></TableCell>}
              {columns.map((column, index) => (
                <TableCell
                  key={index}
                  className="table-header-cell"
                >
                  {column}
                </TableCell>
              ))}
            </TableRow>
          </TableHead>
          <TableBody>
            {filteredData.map((row, rowIndex) => (
              <TableRow key={rowIndex}>
                {showCheckboxes && (
                  <TableCell padding="checkbox">
                    <Checkbox
                      onChange={this.handleCheckboxChange ? (event) => this.handleCheckboxChange(event, rowIndex) : undefined}
                    />
                  </TableCell>
                )}
                {columns.map((column, colIndex) => (
                  <TableCell key={colIndex}>{row[column]}</TableCell>
                ))}
              </TableRow>
            ))}
          </TableBody>
        </Table>
      </div>
    );
  }
}

export default TableComponent;
