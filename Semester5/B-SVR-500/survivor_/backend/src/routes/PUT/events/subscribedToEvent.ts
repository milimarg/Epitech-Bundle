import express from 'express';
import { dbWrapper } from "../../../index";

const router = express.Router();

router.put('/events/:id/subscribed', (req, res) => {
    const id = req.params.id;
    const body = req.body;
    const token = body.token;
    const customerId = body.customerId;
    try {
      dbWrapper.subscribedToEvent(token, parseInt(id), customerId).then((data) => {
        res.send(data);
      });
    } catch (error) {
      console.error(`Couldn't subscribe customer: ${error}`);
    }
});

module.exports = router;
