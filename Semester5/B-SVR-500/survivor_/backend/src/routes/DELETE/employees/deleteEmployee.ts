import express from 'express';
import {dbWrapper} from "../../../index";

const router = express.Router();

router.delete('/employees/delete/:id', (req, res) => {

    const token = req.query.token as string;
    const id = req.params.id;
    try {
        dbWrapper.deleteEmployee(token, parseInt(id)).then();
        res.send(`Successfully deleted customer n°${id}`);
    } catch (error) {
        console.error(`Tried to delete employee ${id}: got error ${error}`);
    }
});

module.exports = router;
