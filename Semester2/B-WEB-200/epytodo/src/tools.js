const jwt = require('jsonwebtoken');
const bcrypt = require('bcryptjs');

module.exports.is_email = function(email) {
    const regex = /(?:[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*|"(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21\x23-\x5b\x5d-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])*")@(?:(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?|\[(?:(?:(2(5[0-5]|[0-4][0-9])|1[0-9][0-9]|[1-9]?[0-9]))\.){3}(?:(2(5[0-5]|[0-4][0-9])|1[0-9][0-9]|[1-9]?[0-9])|[a-z0-9-]*[a-z0-9]:(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21-\x5a\x53-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])+)\])/;

    return (regex.test(email));
}

module.exports.getCurrentSqlDate = function () {
    const date = new Date();

    date.setTime(date.getTime() + (2 * 60 * 60 * 1000));
    return(date.toISOString().slice(0, 19).replace('T', ' '));
}

function checkBodyLen (body, len) {
    return (Object.keys(body).length === len);
}

module.exports.checkValueExists = function (body, str_to_check) {
    if (!checkBodyLen(body, str_to_check.length)) {
        return false;
    }
    for (let element of str_to_check) {
        if (body[element] === undefined) {
            return false;
        }
    }
    return true;
}

module.exports.hashPassword = function (password) {
    const salt = bcrypt.genSaltSync(10);

    return bcrypt.hashSync(password, salt);
}

module.exports.createToken = function (id) {
    const user = {
        id: id,
    }
    const secretKey = process.env.SECRET;
    const token = jwt.sign(user, secretKey);
    return (token);
}

function getTokenName (bearerToken) {
    return (bearerToken.slice(7, bearerToken.length + 1));
}

function displayMsgTokenIsValid(token, res) {
    if (token === undefined) {
        res.json({"msg": "No token, authorization denied"});
    }
    if (token !== undefined) {
        res.json({"msg": "Token is not valid"});
    }
}

function tokenIsValidHandler (token, id) {
    const secretKey = process.env.SECRET;

    if (token === undefined) {
        return false;
    }
    try {
        const decoded = jwt.verify(token, secretKey);
        id = parseInt(id, 10);
        return decoded.id === id;
    } catch (error) {
        return false;
    }
}

function tokenIsValid(token, id, res, display) {
    let tokenName = 0;

    if (token === undefined) {
        displayMsgTokenIsValid(token, res);
        return false;
    }
    tokenName = getTokenName(token);
    if (tokenIsValidHandler(tokenName, id)) {
        return true;
    } else {
        if (display) {
            displayMsgTokenIsValid(tokenName, res);
        }
        return false;
    }
}

module.exports.findUserTokenInDatabase = function (connection, token, res) {
    return new Promise((resolve, reject) => {
        if (token === undefined) {
            resolve(null);
        }
        connection.query(`SELECT * FROM user`,
            function (err, results, fields) {
                for (let result of results) {
                    if (tokenIsValid(token, result["id"], res, false)) {
                        resolve(result);
                    }
                }
                resolve(null);
            });
    });
}

module.exports.tokenIsValid = tokenIsValid;
module.exports.checkBodyLen = checkBodyLen;
module.exports.getTokenName = getTokenName;
module.exports.displayMsgTokenIsValid = displayMsgTokenIsValid;
