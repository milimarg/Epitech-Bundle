import express from 'express';
import { dbWrapper } from "../../../index";

const router = express.Router();

router.put('/events/:id/setlimit', (req, res) => {
    const id = req.params.id;
    const body = req.body;
    const token = body.token;
    const limit = body.limit;
    try {
      dbWrapper.setLimitEvent(token, parseInt(id), limit).then((data) => {
        res.send(data);
      });
    } catch (error) {
      console.error(`Couldn't set limit for Event: ${error}`);
    }
});

module.exports = router;
