const {is_email} = require("../../tools.js");
const bcrypt = require("bcryptjs");

function compare_hashed_password(connection, email_or_id, password, res) {
    const is_email_bool = is_email(email_or_id);
    const check_email = `SELECT * FROM user WHERE email LIKE "${email_or_id}"`;
    const check_id = `SELECT * FROM user WHERE id LIKE "${email_or_id}"`;

    return new Promise((resolve, reject) => {
        connection.query((is_email_bool) ? check_email : check_id,
            function (err, results, fields) {
            if (results.length !== 0) {
                bcrypt.compare(password, results[0]["password"], (err, results2) => {
                    if (results2) {
                        resolve(results);
                    } else {
                        resolve(null);
                    }
                });
            } else {
                resolve(null);
            }
        });
    });
}

module.exports.userExists = function (connection, email_or_id, password, res) {
    return new Promise((resolve, reject) => {
        compare_hashed_password(connection, email_or_id, password, res).then((results) => {
            resolve(results);
        });
    });
}
