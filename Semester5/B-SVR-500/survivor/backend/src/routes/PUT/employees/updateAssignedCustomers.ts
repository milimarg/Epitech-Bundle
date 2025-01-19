import express from 'express';
import * as Types from "../../../api/types";
import {dbWrapper} from "../../../index";

const router = express.Router();

router.put('/employees/:id/assignCustomers', (req, res) => {
  const id = req.params.id;
  const token = req.body.token;
  const assigned = req.body.assigned;
  try {
    dbWrapper.assignCustomers(token, parseInt(id), assigned).then((data) => {
      res.send(data);
    });
  } catch (error) {
    console.error(`Couldn't assign customers at employee: ${error}`)
  }
});

module.exports = router;
