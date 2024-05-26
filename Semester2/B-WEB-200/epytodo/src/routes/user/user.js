const {is_email, checkValueExists, findUserTokenInDatabase, displayMsgTokenIsValid, tokenIsValid} = require("../../tools");
const {userExists} = require("./user.query");

module.exports.getAllUsers = function (app, connection) {
    app.get("/user", (req, res) => {
        const token = req.headers.authorization;

        findUserTokenInDatabase(connection, token, res).then((results) => {
            if (results === null) {
                displayMsgTokenIsValid(token, res);
            } else {
                connection.query(
                    `SELECT * FROM user`,
                    function (err, results2, fields) {
                        res.status(200).json(results2);
                    });
            }
        });
    });
}

module.exports.getSpecificUser = function (app, connection) {
    app.get("/users/:id", (req, res) => {
        const token = req.headers.authorization;
        const email_or_id = req.params.id;
        const check_email = `SELECT * FROM user WHERE email LIKE "${email_or_id}"`;
        const check_id = `SELECT * FROM user WHERE id LIKE "${email_or_id}"`;

        if (tokenIsValid(token, email_or_id, res, true)) {
            connection.query((is_email(email_or_id)) ? check_email : check_id,
                function (err, results, fields) {
                    res.status(200).json(results);
            });
        }
    });
}

module.exports.getAllUserTasks = function (app, connection) {
    app.get("/user/todos", (req, res) => {
        const token = req.headers.authorization;

        findUserTokenInDatabase(connection, token, res).then((results) => {
            if (results === null) {
                displayMsgTokenIsValid(token, res);
            } else {
                connection.query(`SELECT * FROM todo WHERE user_id LIKE "${results["id"]}"`,
                    function (err, results, fields) {
                        res.status(200).json(results);
                });
            }
        });
    });
}

module.exports.deleteSpecificUser = function (app, connection) {
    app.delete("/users/:id", (req, res) => {
        const id = req.params.id;
        const token = req.headers.authorization;

        if (tokenIsValid(token, id, res, true)) {
            connection.query(`SELECT * FROM user WHERE id LIKE "${id}"`, (err, results, fields) => {
                if (results.length !== 0) {
                    connection.query(`DELETE FROM user WHERE ID = "${id}"`,
                        function (err, results, fields) {
                            res.status(200).json({"msg": `Successfully deleted record number: ${id}`});
                        });
                } else {
                    res.status(404).json({"msg": "Not found"});
                }
            });
        }
    });
}

module.exports.updateUser = function(app, connection) {
    app.put("/users/:id", (req, res) => {
        const body = req.body;
        const token = req.headers.authorization;
        const id = req.params.id;
        const body_right = checkValueExists(body, ["email", "password", "firstname", "name"]);

        if (tokenIsValid(token, id, res, true)) {
            if (body_right) {
                connection.query(`UPDATE user SET email = ?, password = ?, firstname = ?, name = ? WHERE id LIKE ${id}`,
                    [body["email"], body["password"], body["firstname"], body["name"]], (err, results, fields) => {
                    });
                connection.query(`SELECT * FROM user WHERE id LIKE ${id}`, (err, results, fields) => {
                    res.status(200).json(results);
                });
            } else {
                res.status(404).json({"msg": "Bad parameter"});
            }
        }
    });
}
