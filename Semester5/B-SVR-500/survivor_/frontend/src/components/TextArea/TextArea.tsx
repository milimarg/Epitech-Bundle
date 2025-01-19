import React from 'react';
import { TextField } from '@mui/material';
import './TextArea.css';

type Props = {
  label: string;
  value: string;
  onChange: (event: React.ChangeEvent<HTMLInputElement | HTMLTextAreaElement>) => void;
  placeholder?: string;
  helperText?: string;
  errorMessage?: string;
  disabled?: boolean;
  required?: boolean;
  rows?: number;
  fullWidth?: boolean;
};

class TextArea extends React.Component<Props> {
  render() {
    const {
      label,
      value,
      onChange,
      placeholder = '',
      helperText = '',
      errorMessage = '',
      disabled = false,
      required = false,
      rows = 4,
      fullWidth = false,
    } = this.props;

    return (
      <div className="text-area">
        <TextField
          label={label}
          value={value}
          onChange={onChange}
          placeholder={placeholder}
          helperText={errorMessage || helperText}
          error={!!errorMessage}
          disabled={disabled}
          required={required}
          multiline
          rows={rows}
          fullWidth={fullWidth}
          variant="outlined"
        />
      </div>
    );
  }
}

export default TextArea;
