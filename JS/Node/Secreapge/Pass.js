let countEl=document.getElementById("count-el")
let saveEl=document.getElementById("save-el")
let toastBox=document.querySelector(".toastBox");
let incrButn=document.querySelector(".increment-btn");
let savBtn=document.querySelector(".save-btn");
let isHoldingIncrement=false

let entryCoun=0;
saveEl.textContent="Eated Them: "
countEl.innerText=0
 
function increment() {
  countEl.textContent++;
}

function incrementHold() {
  isHoldingIncrement=true
  while(isHoldingIncrement)
    countEl.textContent++;
}

function incrementLetUp(params) {
  isHoldingIncrement=false
}

function showToast(message, type) {
    const toast = document.createElement('div');
    toast.classList.add('toast', type);
    toast.innerHTML = 
        '<button class="close-btn">X</button>' 
                                    + message;
    toastBox.appendChild(toast);

    const closeButton = 
            toast.querySelector('.close-btn');
    closeButton.addEventListener('click', () => {
        toast.remove();
    });

    setTimeout(() => {
        toast.remove();
    }, 3000);
}

function save() {

  if(countEl.textContent>=100)
    showToast("Why did you do this?",'whyDidYouDoThis')

  let entrStr=""
  const maxEntriesAtOnce=5
  if(entryCoun>=maxEntriesAtOnce){
    saveEl.textContent="Eated Them: ";
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


incrButn.addEventListener('click',()=>{increment()})
savBtn.addEventListener('click',()=>{save()})
