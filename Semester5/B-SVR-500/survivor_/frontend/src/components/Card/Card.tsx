import React from 'react';
import { Card as MuiCard, CardContent, CardActions, Typography, CardMedia } from '@mui/material';
import './Card.css';

type Props = {
  title: string;
  subtitle?: string;
  content: string | React.ReactNode;
  imageUrl?: string;
  imageAlt?: string;
  imageHeight?: number;
  actions?: React.ReactNode;
  width?: string;
  elevation?: number;
};

class Card extends React.Component<Props> {
  render() {
    const {
      title,
      subtitle,
      content,
      imageUrl,
      imageAlt,
      imageHeight,
      actions,
      width = '300px',
      elevation = 3,
    } = this.props;

    return (
      <MuiCard className="card" style={{ width }} elevation={elevation}>
        {imageUrl && <CardMedia
          component="img"
          height={imageHeight ?? 140}
          image={imageUrl}
          alt={imageAlt ?? title}
        />}
        <CardContent>
          <Typography variant="h5" component="div">
            {title}
          </Typography>
          {subtitle && (
            <Typography variant="subtitle1" color="textSecondary">
              {subtitle}
            </Typography>
          )}
          <Typography variant="body2" color="textSecondary">
            {content}
          </Typography>
        </CardContent>
        {actions && <CardActions>{actions}</CardActions>}
      </MuiCard>
    );
  }
}

export default Card;
