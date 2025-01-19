import express from 'express';
import { dbWrapper } from "../../../index";

const router = express.Router();

router.get('/employees/shortme', (req, res) => {
  const token = req.query.token as string;
  try {
    dbWrapper.getShortEmployeeMe(token).then((data) => {
      res.json(data);
    });
  } catch (error) {
    console.error(error);
  }
});

module.exports = router;
