import express from 'express';
import { dbWrapper } from "../../../../index";

const router = express.Router();

router.get('/customers/:id/clothes/:type', (req, res) => {
  const token = req.query.token as string;
  try {
    dbWrapper.getClotheTypeByCustomer(token, parseInt(req.params.id), req.params.type).then((data) => {
      res.json(data);
    });
  } catch (error) {
    console.error(error);
  }
});

module.exports = router;
