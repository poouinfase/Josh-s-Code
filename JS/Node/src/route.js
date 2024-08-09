const express = require("express");
const router = express.Router();
const userController = require("./user-auth.js"); // importing the user controller 

router.post("/sign-up", userController.register);
router.post("/login", userController.login);


module.exports = router;
