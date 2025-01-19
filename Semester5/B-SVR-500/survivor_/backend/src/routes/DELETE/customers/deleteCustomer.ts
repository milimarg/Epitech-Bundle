import express from 'express';
import {dbWrapper} from "../../../index";

const router = express.Router();

router.delete('/customers/delete/:id', (req, res) => {
    const id = req.params.id;

    const token = req.query.token as string;
    try {
        dbWrapper.deleteCustomer(token, parseInt(id)).then();
        res.send(`Deleted Customer n°${id}`);
    } catch (error) {
        console.error(`Tried to delete customer ${id}: got error: ${error}`);
    }
});

module.exports = router;
