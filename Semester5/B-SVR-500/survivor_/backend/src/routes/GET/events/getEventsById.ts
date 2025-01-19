import express from 'express';
import {dbWrapper} from "../../../index";

const router = express.Router();

router.get('/events/:id', (req, res) => {
  const token = req.query.token as string;
  try {
    dbWrapper.getEventById(token, parseInt(req.params.id)).then((data) => {
      res.json(data);
    });
  } catch (error) {
    console.error(error);
  }
});

module.exports = router;
