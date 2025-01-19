import express from 'express';
import { dbWrapper } from "../../../index";

const router = express.Router();

router.post('/login', (req, res) => {
    const email = req.body.email;
    const password = req.body.password;
    try {
      dbWrapper.loginClient(email, password).then((data) => {
        res.json(data);
      });
    } catch (error) {
      console.error(error);
    }
});

module.exports = router;
