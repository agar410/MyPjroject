function changeBlue(){
    $("#header").attr("class", "text-blue");
    console.log(" ran...");
}

function changeGreen(){
    $("#header").attr("class","text-green");
    console.log(" ran...");
}
function chageColor(){
    if($("#header").attr("class")=="text-blue"){
changeGreen();
    }
    else{
changeBlue();
    }
}

function changeColorMain(){
    console.log("changeColorMain ran...");
    $("#btnBlue").on("click",changeBlue);
    $("#btnGreen").on("click",changeGreen);
    $("#header").on("click",chageColor);
}