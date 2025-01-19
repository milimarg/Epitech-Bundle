import React from "react";
import Avatar from "../Avatar/Avatar";
import "./NameAvatar.css";

type Props = {
  src?: string;
  alt: string;
  size?: 'small' | 'medium' | 'large' | 'xlarge';
  sx?: object;
  name?: string;
  surname?: string;
};

class NameAvatarComponent extends React.Component<Props> {
  render() {
    const {
      src,
      alt,
      size = 'large',
      sx,
      name,
      surname
    } = this.props;
    return (
      <div className={"name-avatar-wrapper"}>
        <Avatar
          src={src}
          alt={alt}
          size={size}
          sx={sx}
          name={name}
          surname={surname}
        />
        <span>{name + " " + surname}</span>
      </div>
    );
  }
}

export default NameAvatarComponent;