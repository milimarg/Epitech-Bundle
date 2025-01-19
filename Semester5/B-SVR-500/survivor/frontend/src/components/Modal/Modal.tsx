import React from 'react';
import { Modal as MuiModal, Typography, IconButton, Divider } from '@mui/material';
import CloseIcon from '@mui/icons-material/Close';
import './Modal.css';

type Props = {
  open: boolean;
  onClose: () => void;
  title: string;
  children: React.ReactNode;
  actions?: React.ReactNode;
  fullWidth?: boolean;
  fullHeight?: boolean;
  scroll?: 'paper' | 'body';
};

class Modal extends React.Component<Props> {
  render() {
    const {
      open,
      onClose,
      title,
      children,
      actions,
      fullWidth = false,
      fullHeight = false,
      scroll = 'paper',
    } = this.props;

    return (
      <MuiModal
        open={open}
        onClose={onClose}
        className="modal"
        keepMounted
        sx={{ backdropFilter: 'blur(4px)' }}
      >
        <div
          className={`modal-content ${fullWidth ? 'full-width' : ''} ${fullHeight ? 'full-height' : ''}`}
          aria-labelledby="modal-title"
          aria-describedby="modal-description"
        >
          <div className="modal-header">
            <Typography id="modal-title" variant="h6">
              {title}
            </Typography>
            <IconButton onClick={onClose} aria-label="close">
              <CloseIcon />
            </IconButton>
          </div>
          <Divider />
          <div className="modal-body" style={{ overflowY: scroll === 'body' ? 'auto' : 'hidden' }}>
            {children}
          </div>
          {actions && (
            <div className="modal-footer">
              {actions}
            </div>
          )}
        </div>
      </MuiModal>
    );
  }
}

export default Modal;
