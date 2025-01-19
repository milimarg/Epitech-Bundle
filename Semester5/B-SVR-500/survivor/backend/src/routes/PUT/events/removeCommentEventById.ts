import express from 'express';
import { dbWrapper } from "../../../index";

const router = express.Router();

router.put('/events/removecomment', (req, res) => {
    const body = req.body;
    const token = body.token;
    const commentId = body.commentId;
    try {
      dbWrapper.removeCommentEventById(token, commentId).then((data) => {
        res.send(data);
      });
    } catch (error) {
      console.error(`Couldn't remove comment: ${error}`);
    }
});

module.exports = router;
