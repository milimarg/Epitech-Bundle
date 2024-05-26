require("dotenv").config();
const express = require("express");
const bodyParser = require("body-parser");
const connection = require("./config/db");

const port = process.env.PORT;
const app = express();

require("./middleware/auth.js").middleware(app, bodyParser);
require("./routes/auth/auth.js").register(app, connection);
require("./routes/auth/auth.js").login(app, connection);
require("./routes/user/user.js").getAllUsers(app, connection);
require("./routes/user/user.js").getSpecificUser(app, connection);
require("./routes/user/user.js").getAllUserTasks(app, connection);
require("./routes/user/user.js").deleteSpecificUser(app, connection);
require("./routes/user/user.js").updateUser(app, connection);
require("./routes/todos/todos.js").getAllTasks(app, connection);
require("./routes/todos/todos.js").getSpecificTask(app, connection);
require("./routes/todos/todos.js").createTask(app, connection);
require("./routes/todos/todos.js").deleteTask(app, connection);
require("./routes/todos/todos.js").updateTask(app, connection);

app.listen(port, () => {
    console.log(`Currently listening at: http://localhost:${port}`);
});
