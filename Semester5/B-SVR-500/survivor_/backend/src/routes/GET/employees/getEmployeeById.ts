import express from 'express';
import {dbWrapper} from "../../../index";

const router = express.Router();

router.get('/employees/:id', (req, res) => {
  const token = req.query.token as string;
  try {
    dbWrapper.getEmployee(token, parseInt(req.params.id)).then((data) => {
      res.json(data);
    });
  } catch (error) {
    console.error(error);
    res.send(`couldn't get employee ${req.params.id}`);
  }
});

module.exports = router;
