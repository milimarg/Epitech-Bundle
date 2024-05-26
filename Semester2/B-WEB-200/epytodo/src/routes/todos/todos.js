const {fetchTask, createTask, deleteTask, updateTask} = require("./todos.query.js");
const {checkValueExists, findUserTokenInDatabase} = require("../../tools.js");
const {displayMsgTokenIsValid, tokenIsValid} = require("../../tools");
const {fetchTaskByUser} = require("./todos.query");

module.exports.getAllTasks = function (app, connection) {
    app.get("/todos", (req, res) => {
        const token = req.headers.authorization;

        findUserTokenInDatabase(connection, token, res).then((results) => {
            if (results === null) {
                displayMsgTokenIsValid(token, res);
            } else {
                fetchTaskByUser(connection, results["id"]).then((results) => {
                    res.status(200).json(results);
                });
            }
        });
    });
}

module.exports.getSpecificTask = function (app, connection) {
    app.get("/todos/:id", (req, res) => {
        const id = req.params.id;
        const token = req.headers.authorization;

        fetchTask(connection, id).then((results) => {
            if (results.length === 0) {
                res.status(404).json({"msg": "Not found"});
            }
            if (results.length !== 0 && tokenIsValid(token, results[0]["user_id"], res, true)) {
                res.status(200).json(results);
            }
        });
    });
}

module.exports.createTask = function (app, connection) {
    app.post("/todos", (req, res) => {
        const body = req.body;
        const token = req.headers.authorization;
        const body_right = checkValueExists(body, ["title", "description", "due_time", "user_id", "status"]);

        if (tokenIsValid(token, body["user_id"], res, true)) {
            if (body_right) {
                createTask(connection, body).then((results) => {
                    res.status(201).json(results);
                });
            } else {
                res.status(404).json({"msg": "Bad parameter"});
            }
        }
    });
}

module.exports.deleteTask = function (app, connection) {
    app.delete("/todos/:id", (req, res) => {
        const id = req.params.id;
        const token = req.headers.authorization;

        fetchTask(connection, id).then((results) => {
            if (results.length === 0) {
                res.status(404).json({"msg": "Not found"});
            } else {
                if (tokenIsValid(token, results[0]["user_id"], res, true)) {
                    deleteTask(connection, id, res);
                }
            }
        });
    });
}

module.exports.updateTask = function (app, connection) {
    app.put("/todos/:id", (req, res) => {
        const id = req.params.id;
        const body = req.body;
        const token = req.headers.authorization;
        const body_right = checkValueExists(body, ["title", "description", "due_time", "user_id", "status"]);

        if (tokenIsValid(token, body["user_id"], res, true)) {
            if (body_right) {
                updateTask(connection, id, body, res);
            } else {
                res.status(404).json({"msg": "Bad parameter"});
            }
        }
    });
}
