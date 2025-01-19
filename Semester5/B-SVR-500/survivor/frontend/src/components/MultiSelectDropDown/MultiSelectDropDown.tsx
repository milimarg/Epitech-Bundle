import React from 'react';
import { TextField, MenuItem, Checkbox, ListItemText } from '@mui/material';
import './MultiSelectDropdown.css';

type Option = {
  value: string | number;
  label: string;
};

type Props = {
  label: string;
  options: Option[];
  value: (string | number)[];
  onChange: (event: React.ChangeEvent<{ value: unknown }>) => void;
  required?: boolean;
  placeholder?: string;
  helperText?: string;
  errorMessage?: string;
  disabled?: boolean;
  fullWidth?: boolean;
};

class MultiSelectDropdown extends React.Component<Props> {
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
      fullWidth = false
    } = this.props;

    return (
      <div className="multi-select-dropdown">
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
          slotProps={{
            select: {
              multiple: true,
              renderValue: (selected) => (
                <div className="selected-values">
                  {options
                    .filter(option => (selected as string[]).includes(option.value.toString()))
                    .map(option => (
                      <span key={option.value} className="selected-value">
                        {option.label}
                      </span>
                    ))}
                </div>
              ),
            },
          }}
        >
          {options.map((option) => (
            <MenuItem key={option.value} value={option.value}>
              <Checkbox checked={(value as string[]).includes(option.value.toString())} />
              <ListItemText primary={option.label} />
            </MenuItem>
          ))}
        </TextField>
      </div>
    );
  }
}

export default MultiSelectDropdown;
