import React from "react";
import Avatar from '@mui/material/Avatar';

type Props = {
  src?: string;
  alt: string;
  size?: 'small' | 'medium' | 'large' | 'xlarge';
  sx?: object;
  name?: string;
  surname?: string;
};

class AvatarComponent extends React.Component<Props> {
  render() {
    const {
      src,
      alt,
      size = 'large',
      sx,
      name,
      surname
    } = this.props;

    let displayName = "";

    if (name && name.length > 1)
      displayName += name.charAt(0);
    if (surname && surname.length > 1)
      displayName += surname.charAt(0);

    const sizeMap = {
      small: 24,
      medium: 40,
      large: 56,
      xlarge: 80
    };

    return (
      <Avatar
        src={src}
        alt={alt}
        sx={{ width: sizeMap[size], height: sizeMap[size], ...sx }}
      >{displayName}</Avatar>
    );
  }
}

export default AvatarComponent;
