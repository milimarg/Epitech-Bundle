import './Card.css';

const Card = (props) => {
    return (
        <div className="card-wrapper">
            <span className="card-title">{props.title}</span><br />
            <span className="card-description">{props.description}</span><br />
            <span className="card-due-time">{props.dueTime}</span>
        </div>
    );
}

export default Card;
