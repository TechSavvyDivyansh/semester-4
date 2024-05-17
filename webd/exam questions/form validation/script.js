// loading 
function showForm() {
    document.getElementById("loader").style.display = "none";
    document.getElementById("afterLoadDisplay").style.display = "flex";
}


let timer=document.getElementById('timer')

// Countdown timer
let timeLeft = 5;
let countdownInterval = setInterval(() => {
    timer.innerHTML=timeLeft
    timeLeft--;
    if (timeLeft < -1) {
        showForm(); // Call function to display the form
        clearInterval(countdownInterval);
    }
}, 1000);





// after load display
let email=document.getElementById("email")
let emailPattern=/[a-zA-Z1-3]\w+@(gmail|yahoo|outlook).com/
let emailError=document.getElementById('emailError')
let emailSuccess=document.getElementById('emailSuccess')



email.addEventListener("keyup",(e)=>{
    if(!emailPattern.test(e.target.value))
    {
        emailError.innerHTML=`Enter a proper gmail/yahoo/outlook id`
        emailSuccess.innerHTML=''
    }
    else
    {
        emailError.innerHTML=''
        emailSuccess.innerHTML='✔️'
    }
    if(e.target.value=='')
    {
        emailError.innerHTML=``
        emailSuccess.innerHTML=''
    }
})




let password=document.getElementById('password')
let passError=document.getElementById('passError')
let passSuccess=document.getElementById('passSuccess')
let confirmPassword=document.getElementById('confirmPassword')
let CPassError=document.getElementById('CPassError')
let CPassSuccess=document.getElementById('CPassSuccess')
let passwordPattern=/^(?=.+[!@#$%^_&][0-9])[a-zA-Z0-9!@#$%^_&*]{8,}$/


password.addEventListener("keyup",(e)=>{
    if(e.target.value=="")
    {
        passError.innerHTML=""
        passSuccess.innerHTML=""
    }
    else if(!passwordPattern.test(e.target.value))
    {
        passError.innerHTML="password should be of min 8 characters ,there should be atleast 1 symbol and 1 digit"
        passSuccess.innerHTML=""
        console.log("not found");
    }
    else
    {
        console.log("found");
        passError.innerHTML=""
        passSuccess.innerHTML="✔️"
    }
})

confirmPassword.addEventListener("keyup",(e)=>{
    if(e.target.value!=password.value && e.target.value!="")
    {
          CPassError.innerHTML="password should be same as the previous entered password"
          CPassSuccess.innerHTML=""
    }
    else if(e.target.value=="")
    {
        CPassError.innerHTML=""
        CPassSuccess.innerHTML=""
    }
    else
    {
        CPassError.innerHTML=""
        CPassSuccess.innerHTML="✔️"
    }
})



let bgChanger=document.querySelector(".bgchanger")
bgChanger.addEventListener("click",()=>{
      let currentColor = window.getComputedStyle(document.body).backgroundColor;
      if(currentColor=="rgb(236, 232, 232)")
      {
          document.body.style.backgroundColor="rgb(56, 53, 53)"
          document.body.style.color="white"
        }
        else
        {
            document.body.style.backgroundColor="rgb(236, 232, 232)"
            document.body.style.color="black"
      }
})