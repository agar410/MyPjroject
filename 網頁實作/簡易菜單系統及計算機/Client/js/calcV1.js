function setInput1(e){
    //e: event
    console.log(e);
    var vID =this.id.substring(3);
    var vExpr =$("#expr1").val();
    var vExprLen = vExpr.length;
    var vOp = {
        Add:"+",Sub:"-",Mlt:"*",Div:"/",Dot:".",L:"(",R:")"
    };

    switch(vID){
        case "Cls":
            $("#expr1").val("");
            $("#ans1").val("");
            break;
        case "Del":
            var z=vExpr.substring(0,vExprLen-1);
            $("#expr1").val(z);
            break;
        case "Add": case "Sub": case "Mlt": case "Div" : case "Dot": case "L": case "R":
            $("#expr1").val(vExpr+vOp[vID]);
            break;
        case "Calc":
            SetAns1();
            break;
        default:
            //0~9
            $("#expr1").val(vExpr+vID);
            break;    
                   
    }
}
function SetAns1(){
    var vExpr =$("#expr1").val();
    $("#ans1").val(eval(vExpr));
}
function createHTML(){
    var aData ={
    aButton:[
        {id:"btn7",value:"7"},
        {id:"btn8",value:"8"},
        {id:"btn9",value:"9"},
        {id:"btnL",value:"("},
        {id:"btnR",value:")"},
        {id:"btn4",value:"4"},
        {id:"btn5",value:"5"},
        {id:"btn6",value:"6"},
        {id:"btnAdd",value:"+"},
        {id:"btnSub",value:"-"},
        {id:"btn1",value:"1"},
        {id:"btn2",value:"2"},
        {id:"btn3",value:"3"},
        {id:"btnMlt",value:"*"},
        {id:"btnDiv",value:"/"},
        {id:"btn0",value:"0"},
        {id:"btnDot",value:"."},
        {id:"btnCalc",value:"="},
        {id:"btnDel",value:"←"},
        {id:"btnCls",value:"Delete"},
    ]    
    }

    $.get("/Client/lib/ejs/calcV1.ejs", function(aTemplate){
        var aStringHTML =ejs.render(aTemplate,aData);
        $("#calcV1-tab").html(aStringHTML);
        $("#calcV1-tab .btn").on("click",setInput1);
    });
       
}
function calcV1Main(){
console.log("calcV1Main run");
createHTML();

}