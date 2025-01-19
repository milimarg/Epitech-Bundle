import express from 'express';
import {dbWrapper} from "../../../../index";

const router = express.Router();

router.get('/customers/:id/payments_history', (req, res) => {
  const token = req.query.token as string;
  try {
    dbWrapper.getCustomerPayments(token, parseInt(req.params.id)).then((data) => {
      res.json(data);
    });
  } catch (error) {
    console.error(error);
  }
});

module.exports = router;
