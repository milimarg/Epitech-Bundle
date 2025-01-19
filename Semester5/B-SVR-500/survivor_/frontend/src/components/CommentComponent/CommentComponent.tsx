import React, { Component } from "react";
import NameAvatarComponent from "../NameAvatar/NameAvatar";
import "./CommentComponent.css";

type Props = {
  comment: string;
  canRemove?: boolean;
  onRemove: () => void;
  name: string;
  surname: string;
  image?: string;
};

export default class CommentComponent extends Component<Props> {
  render() {
    const { comment, canRemove, onRemove, name, surname, image } = this.props;

    return (
      <div className="comment-container">
        <NameAvatarComponent
          name={name}
          surname={`${surname}:`}
          src={image}
          alt={`${name} ${surname}`}
        />
        <div className="comment-text">{comment}</div>
        {canRemove && (
          <button onClick={onRemove} className="remove-comment-button">Remove</button>
        )}
      </div>
    );
  }
}
