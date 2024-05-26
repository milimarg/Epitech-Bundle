const {getCurrentSqlDate} = require("../../tools.js");

function fetchTask(connection, id) {
    const check_all = `SELECT * FROM todo`;
    const check_with_id = `SELECT * FROM todo WHERE id LIKE ${id}`;

    return new Promise((resolve, reject) => {
        connection.query((id === "all") ? check_all : check_with_id,
            function (err, results, fields) {
                if (err) {
                    reject(err);
                } else {
                    resolve(results);
                }
            });
    });
}

function fetchTaskByUser(connection, id) {
    const check_with_id = `SELECT * FROM todo WHERE user_id LIKE ${id}`;

    return new Promise((resolve, reject) => {
        connection.query(check_with_id,
            function (err, results, fields) {
            resolve(results);
        });
    });
}

function taskExists(connection, id) {
    return new Promise((resolve, reject) => {
        fetchTask(connection, id).then((results) => {
            resolve(results);
        });
    });
}

function createTask(connection, body) {
    const query = "INSERT INTO todo (title, description, created_at, due_time, status, user_id) VALUES (?, ?, ?, ?, ?, ?)";
    const data = [body["title"], body["description"], getCurrentSqlDate(), body["due_time"], body["status"], body["user_id"]];

    return new Promise((resolve, reject) => {
        connection.query(query, data, function (err, results, fields) {
            if (err) {
                reject(err);
            } else {
                resolve(fetchTask(connection, results.insertId));
            }
        });
    });
}

function deleteTask(connection, id, res) {
    const query = `DELETE FROM todo WHERE id LIKE "${id}"`;

    taskExists(connection, id).then((exists) => {
        if (exists) {
            connection.query(query, (err, results, fields) => {
                res.status(200).json({"msg": `Successfully deleted record number: ${id}`});
            });
        } else {
            res.status(404).json({"msg": "Not found"});
        }
    });
}

function queryUpdateTask(connection, id, body, res) {
    connection.query(`UPDATE todo SET title = ?, description = ?, due_time = ?, user_id = ?, status = ? WHERE id LIKE ${id}`,
        [body["title"], body["description"], body["due_time"], body["user_id"], body["status"]], (err, results) => {
    });
    connection.query(`SELECT * FROM todo WHERE id LIKE ${id}`, (err, results) => {
        res.status(200).json(results);
    });
}

function updateTask(connection, id, body, res) {
    taskExists(connection, id).then((exists) => {
        if (exists) {
            queryUpdateTask(connection, id, body, res);
        } else {
            res.status(404).json({"msg": "Not found"});
        }
    });
}

module.exports.fetchTask = fetchTask;
module.exports.fetchTaskByUser = fetchTaskByUser;
module.exports.taskExists = taskExists;
module.exports.createTask = createTask;
module.exports.deleteTask = deleteTask;
module.exports.updateTask = updateTask;
