import './Login.css';
import {Link, useNavigate} from "react-router-dom";

async function fetchUser(email, password, firstName, lastName) {
    const response = await fetch('http://localhost:3000/register', {
        method: 'POST',
        headers: {
            'Accept': '*/*',
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({
            "email": email,
            "password": password,
            "firstname": firstName,
            "name": lastName
        })
    });
    if (response.ok) {
        const data = await response.json();
        return (data);
    } else {
        throw new Error("(register) Request error");
    }
}

function Register() {
    const navigate = useNavigate();
    const submitForm = async (event) => {
        event.preventDefault();
        const formData = new FormData(event.target);
        const email = formData.get("email");
        const password = formData.get("password");
        const firstname = formData.get("firstname");
        const lastname = formData.get("lastname");
        try {
            const data = await fetchUser(email, password, firstname, lastname);
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
                    <h1 className="title">Register</h1>
                </div>
                <div className="field">
                    <label htmlFor="firstname">First name</label>
                    <div className="textbox">
                        <input type="text" name="firstname" required />
                    </div>
                </div>
                <div className="field">
                    <label htmlFor="lastname">Last name</label>
                    <div className="textbox">
                        <input type="text" name="lastname" required />
                    </div>
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
                    <Link className="link" to="/login">Connect to existing account</Link>
                </div>
            </form>
        </div>
    );
}

export default Register;
