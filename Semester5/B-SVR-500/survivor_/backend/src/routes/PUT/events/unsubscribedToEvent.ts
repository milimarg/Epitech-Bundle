import express from 'express';
import { dbWrapper } from "../../../index";

const router = express.Router();

router.put('/events/:id/unsubscribed', (req, res) => {
    const id = req.params.id;
    const body = req.body;
    const token = body.token;
    const customerId = body.customerId;
    try {
      dbWrapper.unsubscribedToEvent(token, parseInt(id), customerId).then((data) => {
        res.send(data);
      });
    } catch (error) {
      console.error(`Couldn't unsubscribe customer: ${error}`);
    }
});

module.exports = router;
