import React from 'react';
import { Button as MuiButton, CircularProgress } from '@mui/material';
import { styled } from '@mui/material/styles';
import './Button.css';

type Props = {
  text: string;
  onClick: () => void;
  color?: "inherit" | "primary" | "secondary" | "success" | "error" | "info" | "warning";
  size?: 'small' | 'medium' | 'large';
  variant?: 'text' | 'outlined' | 'contained';
  disabled?: boolean;
  loading?: boolean;
  fullWidth?: boolean;
  startIcon?: React.ReactNode;
  endIcon?: React.ReactNode;
};

const LargeButton = styled(MuiButton)({
  textTransform: 'none',
  fontFamily: 'arial',
  fontSize: '2rem',
  padding: '0.8rem 2.5rem',
  fontWeight: 'bold',
});

const SmallButton = styled(MuiButton)({
  textTransform: 'none',
  fontFamily: 'arial',
  fontSize: '1rem',
  padding: '0.5rem 1.25rem',
  fontWeight: 'bold',
});

class Button extends React.Component<Props> {
  render() {
    const {
      text,
      onClick,
      color = 'primary',
      size = 'medium',
      variant = 'contained',
      disabled = false,
      loading = false,
      fullWidth = false,
      startIcon,
      endIcon
    } = this.props;

    const SelectedButton = size === 'small' ? SmallButton : LargeButton;

    return (
      <div className={`button-container ${fullWidth ? 'fullWidth' : ''}`}>
        <SelectedButton
          color={color}
          size={size}
          variant={variant}
          onClick={onClick}
          disabled={disabled || loading}
          fullWidth={fullWidth}
          startIcon={startIcon}
          endIcon={endIcon}
          className="custom-button"
          disableRipple
        >
          {text}
          {loading && (
            <CircularProgress size={24} color="inherit" className="button-spinner" />
          )}
        </SelectedButton>
      </div>
    );
  }
}

export default Button;
