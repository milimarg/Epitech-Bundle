const {getCurrentSqlDate, createToken, hashPassword, checkValueExists, tokenIsValid} = require("../../tools.js");
const {userExists} = require("../user/user.query.js");
const {getTokenName} = require("../../tools");

function createUser(connection, body, res) {
    const password = hashPassword(body["password"]);
    let token = 0;

    connection.query(
        'INSERT INTO user (email, password, name, firstname, created_at) VALUES (?, ?, ?, ?, ?)',
        [body["email"], password, body["name"], body["firstname"], getCurrentSqlDate()],
        function (err, results, fields) {
            if (err) {
                res.status(500).json({"msg": "Internal server error"});
            } else {
                token = createToken(results.insertId);
                res.status(201).json({"token": token});
            }
        }
    );
}

function logUser(connection, res, results) {
    const id = results[0]["id"];
    const token = createToken(id);

    res.status(200).json({"token": token});
}

module.exports.register = function (app, connection) {
    app.post("/register", (req, res) => {
        const body = req.body;
        const body_right = checkValueExists(body, ["email", "name", "firstname", "password"]);

        if (body_right) {
            userExists(connection, body["email"], body["password"], res).then((results) => {
                if (results === null) {
                    createUser(connection, body, res);
                } else {
                    res.status(403).json({"msg": "Account already exists"});
                }
            });
        } else {
            res.status(404).json({"msg": "Bad parameter"});
        }
    });
}

module.exports.login = function (app, connection) {
    app.post("/login", (req, res) => {
        const body = req.body;
        const body_right = checkValueExists(body, ["email", "password"]);

        if (body_right) {
            userExists(connection, body["email"], body["password"], res).then((results) => {
                if (results !== null) {
                    logUser(connection, res, results);
                } else {
                    res.status(403).json({"msg": "Invalid Credentials"});
                }
            });
        } else {
            res.status(404).json({"msg": "Bad parameter"});
        }
    });
}
