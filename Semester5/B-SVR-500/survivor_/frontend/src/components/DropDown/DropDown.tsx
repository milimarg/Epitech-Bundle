import React from 'react';
import { TextField, MenuItem } from '@mui/material';
import './DropDown.css';

type Option = {
  value: string | number;
  label: string;
};

type Props = {
  label: string;
  options: Option[];
  value: string | number;
  onChange: (event: React.ChangeEvent<HTMLInputElement>) => void;
  required?: boolean;
  placeholder?: string;
  helperText?: string;
  errorMessage?: string;
  disabled?: boolean;
  fullWidth?: boolean;
};

class DropDown extends React.Component<Props> {
  render() {
    const {
      label,
      options,
      value,
      onChange,
      required = false,
      placeholder = '',
      helperText = '',
      errorMessage = '',
      disabled = false,
      fullWidth = false,
    } = this.props;

    return (
      <div className="dropdown">
        <TextField
          select
          label={label}
          value={value}
          onChange={onChange}
          required={required}
          placeholder={placeholder}
          helperText={errorMessage || helperText}
          error={!!errorMessage}
          disabled={disabled}
          fullWidth={fullWidth}
          variant="outlined"
        >
          {options.map((option) => (
            <MenuItem key={option.value} value={option.value}>
              {option.label}
            </MenuItem>
          ))}
        </TextField>
      </div>
    );
  }
}

export default DropDown;
