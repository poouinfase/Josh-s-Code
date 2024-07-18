const express=require('express')
const app=express()

const port =3000;

app.listen(port,()=>{console.log(`App start at http://localhost:${port}`)})

app.get('/secret/',(req,res)=>{res.sendFile("./Secreapge/pass.html",{root:__dirname})})
app.get('/pass.css',(req,res)=>{res.sendFile("./Secreapge/pass.css",{root:__dirname})})
app.get('/my-descent-into-madness-is-complete-madness.gif',(req,res)=> { res.sendFile("./Secreapge/my-descent-into-madness-is-complete-madness.gif",{ root : __dirname}) })
app.get('/Pass.js',(req,res)=>{res.sendFile("./Secreapge//Pass.js",{root:__dirname})})

app.get('/',(req,res)=> { res.sendFile("./IndexPage/index.html",{root:__dirname}) })
app.get('/ind.css',(req,res)=>{res.sendFile("./IndexPage/ind.css",{root:__dirname})})
app.get('/MyMindIslost.gif',(req,res)=> { res.sendFile("./IndexPage/MyMindIslost.gif",{ root : __dirname}) })


//   res.send(`
// <h1>YOU ARE BEING SENT TO BRAZIL DO NOT RESIST</h1>
// <meta http-equiv="refresh" content="5; URL=http://localhost:${port}/secret"/>
// `)

// app.get('/log',(req,res)=>
// {   
//     const files=["./index.html","./Pass.js","./pass.css","./my-descent-into-madness-is-complete-madness.gif"];
//     const archiveName="stuff.zip";
//
//   res.set('Content-Type', 'application/zip');
//   res.set('Content-Disposition', `attachment; filename=${archiveName}`);
//   res.zip(files, archiveName, (err) => {
//     if (err) {
//       console.log('Error sending files:', err);
//     } else {
//       console.log('Files sent successfully');
//     }
//   });
//   })

// app.get('/log/Pass.js',(req,res)=>
// {
//     res.sendFile("./Pass.js",{ root : __dirname})
//   })
//
// app.get('/log/pass.css',(req,res)=>
// {
//     res.sendFile("./pass.css",{ root : __dirname})
//   })
//
