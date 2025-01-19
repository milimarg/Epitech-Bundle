import React from 'react';
import { FormControlLabel, Checkbox as MuiCheckbox, FormGroup, FormHelperText } from '@mui/material';
import './CheckBox.css';

type Props = {
  label: string;
  checked: boolean;
  onChange: (event: React.ChangeEvent<HTMLInputElement>) => void;
  disabled?: boolean;
  required?: boolean;
  errorMessage?: string;
  helperText?: string;
};

class CheckBox extends React.Component<Props> {
  render() {
    const {
      label,
      checked,
      onChange,
      disabled = false,
      required = false,
      errorMessage = '',
      helperText = ''
    } = this.props;

    return (
      <div className="checkbox-container">
        <FormGroup>
          <FormControlLabel
            control={
              <MuiCheckbox
                checked={checked}
                onChange={onChange}
                disabled={disabled}
                required={required}
              />
            }
            label={label}
          />
          {helperText && !errorMessage && (
            <FormHelperText className="helper-text">{helperText}</FormHelperText>
          )}
          {errorMessage && (
            <FormHelperText error className="error-text">{errorMessage}</FormHelperText>
          )}
        </FormGroup>
      </div>
    );
  }
}

export default CheckBox;
