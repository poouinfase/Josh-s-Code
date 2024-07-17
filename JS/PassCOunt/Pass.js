let countEl=document.getElementById("count-el")
let saveEl=document.getElementById("save-el")
let entryCoun=0;
saveEl.textContent="Ated Them: "
countEl.innerText=0
 
function increment() {
  countEl.textContent++;
}

function save() {
  let entrStr=""
  const maxEntriesAtOnce=5
  if(entryCoun>=maxEntriesAtOnce){
    saveEl.textContent="Ated Them: ";
    entryCoun=0;
  }

   if(entryCoun!=0)
        entrStr+=" - "
  entryCoun++
  entrStr += countEl.textContent
  saveEl.textContent += entrStr

  countEl.textContent=0;
  console.log(saveEl.textContent);
}
