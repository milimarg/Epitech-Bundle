import express from 'express';
import * as Types from "../../../api/types";
import {dbWrapper} from "../../../index";

const router = express.Router();

router.post('/employees/create', (req, res) => {
    const body = req.body;
    const password = body.password;
    const employee: Types.Employee = {
        id: 0,
        email: body.email,
        name: body.name,
        surname: body.surname,
        birth_date: body.birth_date,
        gender: body.gender,
        work: body.work,
        image: body.image,
        unix_time: 0,
        assigned_customers: []
    };
    dbWrapper.registerEmployee(employee, password).then();
    res.send(`Employee successfully created`);
});

module.exports = router;
