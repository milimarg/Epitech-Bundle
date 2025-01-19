import express from 'express';
import { dbWrapper } from "../../../index";
import * as Types from "../../../api/types";

const router = express.Router();

router.put('/events/addcomment', (req, res) => {
    const body = req.body;
    const token = body.token;
    const comment = body.comment;
    try {
      dbWrapper.addCommentEventById(token, comment).then((data) => {
        res.send(data);
      });
    } catch (error) {
      console.error(`Couldn't add comment: ${error}`);
    }
});

module.exports = router;
