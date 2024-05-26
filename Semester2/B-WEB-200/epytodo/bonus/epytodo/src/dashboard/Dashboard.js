import './Dashboard.css';
import Card from '../card/Card';
import {useState} from "react";

async function fetchTasks(token) {
    const response = await fetch('http://localhost:3000/todos', {
        method: 'GET',
        headers: {
            'Accept': '*/*',
            'Content-Type': 'application/json',
            'Authorization': 'Bearer ' + token
        }
    });
    if (response.ok) {
        const data = await response.json();
        return (data);
    } else {
        throw new Error("(get todos) Request error");
    }
}

function Dashboard() {
    const [dataLoaded, setDataLoaded] = useState(false);
    const [components, setComponents] = useState([]);

    const addComponent = async () => {
        const token = localStorage.getItem("token");
        const tasks = await fetchTasks(token);
        for (let task of tasks) {
            setComponents(prevComponents => [...prevComponents, <Card title={task["title"]} description={task["description"]} dueTime={task["due_time"]} />]);
        }
    };
    if (dataLoaded === false) {
        setDataLoaded(true);
        console.log("test");
        addComponent().then(r => {
        });
    }
    return (
        <div className="dashboard-wrapper">
            <div className="nav">
                <span>Settings</span>
                <span>Log out</span>
            </div>
            <div className="cards">{components}</div>
        </div>
    );
}

export default Dashboard;
