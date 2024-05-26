import './Login.css';
import {Link, useNavigate} from "react-router-dom";

async function fetchUser(email, password) {
    const response = await fetch('http://localhost:3000/login', {
        method: 'POST',
        headers: {
            'Accept': '*/*',
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({
            "email": email,
            "password": password
        })
    });
    if (response.ok) {
        const data = await response.json();
        return (data);
    } else {
        throw new Error("(register) Request error");
    }
}

function Login() {
    const navigate = useNavigate();
    const submitForm = async (event) => {
        event.preventDefault();
        const formData = new FormData(event.target);
        const email = formData.get("email");
        const password = formData.get("password");
        try {
            const data = await fetchUser(email, password);
            localStorage.setItem("token", data["token"]);
            navigate("/dashboard");
        } catch (error) {
            console.log(`(register) try/catch error`, error);
        }
    };

    return (
        <div className="login-wrapper">
            <form onSubmit={submitForm}>
                <div>
                    <h1 className="title">Log in</h1>
                </div>
                <div className="field">
                    <label htmlFor="email">Email</label>
                    <div className="textbox">
                        <input type="text" name="email" required />
                    </div>
                </div>
                <div className="field">
                    <label htmlFor="password">Password</label>
                    <div className="textbox">
                        <input type="text" name="password" required />
                    </div>
                </div>
                <div className="field">
                    <input type="submit" value="Continue with password" />
                </div>
                <div>
                    <Link className="link" to="/register">Create an account</Link>
                </div>
            </form>
        </div>
    );
}

export default Login;
