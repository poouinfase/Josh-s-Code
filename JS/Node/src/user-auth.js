const bcrypt=require("bcrypt");

const User=require("./Schema.js")


const register=async (req,res)=>{
  const user={
    displayname:req.body.username,
    email:req.body.email,
    passwordHash:req.body.hash,
    passwordSalt:req.body.salt,
  }
  const userEmail = await User.findOne({email:user.email})
  const userName = await User.findOne({displayname:user.displayname})
  if(userEmail){
    res.status(409).json({
        message: "Email Already Used",
      });
  }
  if(userName){
    res.status(409).json({
        message: "Username Already registered",
      });
  }

  await User.create(user)
  .then((user) => {
        res.status(201).json({
          message: "Registration successful",
          user,
        });
      });

}

const login=async (req,res)=>{
  const {em,password}=req.body
  const user=User.findOne({em})
  if(!user){
    console.log(em+ " has no registed account")
      return res.status(401).json({
        message: "User not found",
      });
  }

  const has=bcrypt.hash(password,user.passwordSalt)
  if(has==user.passwordHash){
      return res.status(200).json({
        message: "Login successful",
        user: {
          email: user.email,
        },
      });
  }

};

module.exports = {
  register,
  login,
};
