import express from 'express';
import {dbWrapper} from "../../../index";
import * as Types from "../../../api/types";

const router = express.Router();

router.post('/customers/create', (req, res) => {
    const body = req.body;
    const password = body.password;
    const customer: Types.Customer = {
        id: 0,
        email: body.email,
        name: body.name,
        surname: body.surname,
        birth_date: body.birth_date,
        gender: body.gender,
        description: body.description,
        astrological_sign: body.astrological_sign,
        phone_number: body.phone_number,
        address: body.address,
        image: body.image,
        unix_time: 0
    };
    dbWrapper.registerCustomer(customer, password).then();
    res.send(`Customer n°${customer.id} successfully created`);
});

module.exports = router;
