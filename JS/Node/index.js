const express = require('express');
const app = express();
const router=require('./src/route')

const {connectToDb}=require('./src/db');

const port = 3000;

connectToDb();

const rootDir=`./`

app.get('/secret/',(req,res)=>{res.sendFile("./Secreapge/pass.html",{root:rootDir})})
app.get('/pass.css',(req,res)=>{res.sendFile("./Secreapge/pass.css",{root:rootDir})})
app.get('/my-descent-into-madness-is-complete-madness.gif',(req,res)=> { res.sendFile("./Secreapge/my-descent-into-madness-is-complete-madness.gif",{ root : rootDir}) })
app.get('/Pass.js',(req,res)=>{res.sendFile("./Secreapge//Pass.js",{root:rootDir})})

app.get('/',(req,res)=> { res.sendFile("./IndexPage/index.html",{root:rootDir}) })
app.get('/ind.css',(req,res)=>{res.sendFile("./IndexPage/ind.css",{root:rootDir})})
app.get('/MyMindIslost.gif',(req,res)=> { res.sendFile("./IndexPage/MyMindIslost.gif",{ root : rootDir}) })

app.listen(port,()=>{console.log(`App start at http://localhost:${port}`)})

//U
