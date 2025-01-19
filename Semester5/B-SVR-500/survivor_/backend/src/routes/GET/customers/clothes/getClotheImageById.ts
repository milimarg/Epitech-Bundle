import express from 'express';
import { dbWrapper } from "../../../../index";

const router = express.Router();

router.get('/clothes/:id/image', (req, res) => {
  const token = req.query.token as string;
  try {
    dbWrapper.getClotheById(token, parseInt(req.params.id)).then((data) => {
      res.send(data.var?.source);
    });
  } catch (error) {
    console.error(error);
  }
});

module.exports = router;
