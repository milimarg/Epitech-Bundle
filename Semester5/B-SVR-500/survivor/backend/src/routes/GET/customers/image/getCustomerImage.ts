import express from 'express';
import {dbWrapper} from "../../../../index";

const router = express.Router();

router.get('/customers/:id/image', (req, res) => {
  const token = req.query.token as string;
  try {
    dbWrapper.getCustomerById(token, parseInt(req.params.id)).then((data) => {
      res.send(data.var?.image);
    });
  } catch (error) {
    console.error(error);
  }
});

module.exports = router;
