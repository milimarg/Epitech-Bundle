import React from 'react';

type Props = {
  src: string;
  alt: string;
  width?: string;
  height?: string;
};

class ImageDisplayer extends React.Component<Props> {
  isBase64 = (str: string) => {
    try {
      return btoa(atob(str)) === str;
    } catch (err) {
      return false;
    }
  };

  render() {
    const {
      src,
      alt,
      width = '100%',
      height = 'auto'
    } = this.props;

    const imageSrc = this.isBase64(src) ? 'data:image/png;base64, ' + src : src;

    return (
      <div className="image-container">
        <img src={imageSrc} alt={alt} style={{ width, height }} />
      </div>
    );
  }
}

export default ImageDisplayer;