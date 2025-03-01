import express from 'express';
import { dbWrapper } from "../../../index";

const router = express.Router();

router.get('/customers/me', (req, res) => {
  const token = req.query.token as string;
  try {
    dbWrapper.getCustomerMe(token).then((data) => {
      res.json(data);
    });
  } catch (error) {
    console.error(error);
  }
});

module.exports = router;
