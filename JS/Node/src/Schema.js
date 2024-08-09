const mongoose = require("mongoose");
const Schema = mongoose.Schema;

const UserSchema = new Schema({
   displayname: {
   type: String,
   required: true
  },
  email: {
   type: String,
   required: true
  },
  passwordHash: {
   type: String,
   required: true
  },
  passwordSalt:{
    type: String,
    required: true
  },
  createdAt: {
   type: Date,
   default: Date.now
  },
  updatedAt: {
   type: Date,
   default: Date.now
  },
  tombstone:{
    type:Boolean,
    default:false
  }
});

module.exports = mongoose.model("User", UserSchema);
