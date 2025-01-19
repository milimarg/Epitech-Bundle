import React from 'react';
import { TextField } from '@mui/material';
import './InputField.css';

type Props = {
  label: string;
  type?: string;
  value: string;
  onChange: (event: React.ChangeEvent<HTMLInputElement>) => void;
  required?: boolean;
  placeholder?: string;
  helperText?: string;
  errorMessage?: string;
  disabled?: boolean;
  fullWidth?: boolean;
};

class InputField extends React.Component<Props> {
  render() {
    const {
      label,
      type = 'text',
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
      <div className="input-field">
        <TextField
          label={label}
          type={type}
          value={value}
          onChange={onChange}
          required={required}
          placeholder={placeholder}
          helperText={errorMessage || helperText}
          error={!!errorMessage}
          disabled={disabled}
          fullWidth={fullWidth}
          variant="outlined"
        />
      </div>
    );
  }
}

export default InputField;
