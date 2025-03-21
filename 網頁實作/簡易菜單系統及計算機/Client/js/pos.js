function chgTot(){
    $("#bag").val($("#outside").prop("checked") ? $("#outside").val() : 0);
    $("#rate").val($("#extra").prop("checked") ? $("#extra").val() : 0);
    var a =$("#subTotal").val();
    var b =0;// var b = $("#rate").val();
    var c =0;// var c = $("#bag").val();
    $("#total_pos").val(Math.round(a*1+a*(b/100)+c*1));
    
}

function chgSubTotal(){
    $("#subTotal").val($("#unitPrice").val()*$("#qty").val());
    chgTot();
}

function showStatus(){
    n=$("input[name='styles']:checked").val();
    $("#unitPrice").val(price[n][$("#menus option:selected").index()]);
    chgSubTotal();
}

function chg(){
    var n =typeof this.value =="string"?this.value:"0";
    $("#menus option").remove();
    for(var i in opt[n]){
        var opt1 =new Option(opt[n][i],price[n][i]);
        $("#menus").append(opt1);
    }
    showStatus();
}

function setTotal(t){
orderTotal =t*1;
$("#orderTotal").html(orderTotal);
$("#txtOrderID").html($("#orderID").val());
}

function addItem(){
    var n = $("input[name = 'styles']:checked").val();
    var index = $("#menus option:selected").index();
    var qty = $("#qty").val();
    var subTotal = $("#subTotal").val();

    var obj = {
        styles: n,
        menu_index: index,
        qty: qty,
        itemName: opt[n][index],
        unitPrice: price[n][index]
    };
    orderList.push(obj);
    setTotal(orderTotal + subTotal * 1);
    $.get("/Client/lib/ejs/posTbody.ejs", aTemplate => {
        const newItem = ejs.render(aTemplate, {
            totalRows: orderList.length,
            itemName: opt[n][index],
            unitPrice: price[n][index],
            qty: qty,
            subTotal: subTotal
        });
        $("#orderList").append(newItem);
    });
}

function removeAll(){
    orderList = [];
    $("#orderList").empty();
    setTotal(0);
}

function checkOut(){
    $.ajax({
     url:"/Server/checkOut.php",//這裡要改
     method: "POST",
     date: {
         orderID: $("#orderID").val(),
         orderList: orderList,
         orderTotal: orderTotal
     },

     success:function(rsp){
         console.log(rsp);
     }
    });
    ++seqNo;
    setOrderID();
    removeAll();
}

function delOneRow(e){
    var n =this.id.substring(4)*1;
    setTotal(orderTotal-orderList[n-1].unitPrice * orderList[n-1].qty);
    orderList.splice(n-1,1);
    
    $("#item_"+n).remove();
    var m=orderList.length;

    console.log(m);
    for(var i=n+1;i<=m+1;++i){
        //n
        const oldNo = i;
        const newNo = i-1;
        $("#item_"+oldNo).attr("id","item_"+newNo);
        let thisItemHead = $("#item_head_"+oldNo);
        thisItemHead.attr("id","item_head_"+newNo);
        thisItemHead.html(newNo);
       
        $("#btn_"+oldNo).attr("id","btn_"+newNo);    
    }
    console.log($("#orderList"));
}

function setOrderID(){
    var today =new Date();
    var sM =numeral(today.getMonth()+1).format("00");
    var sD =numeral(today.getDate()).format("00");
    var sN =numeral(seqNo).format("0000");

    $("#orderID").val(today.getFullYear()+sM+sD+sN);
}

function posMain(){
console.log("posMain run")   ;
$("input[name='styles']").on("change",chg);
$("#menus").on("change", showStatus);
$("#qty").on("change", showStatus);
 $("#outside").on("change",chgTot);//
 $("#extra").on("change",chgTot);//
$("#addItem").on("click", addItem);
$("#removeAll").on("click", removeAll);
$("#checkOut").on("click", checkOut);
$(".table tbody").on("click",".btn", delOneRow);
chg();

setOrderID();
}


var opt,price;
opt = [
    ["00>燒餅","01>油條","02豆漿"],
    ["10>漢堡","11>薯餅","12可樂","13奶茶"],
    ["20>馬鈴薯","21>玉米蛋餅","22>起司蛋餅","23>奶昔"]
];
price =[
    [10,15,20],
    [20,25,15,25],
    [50,35,25,15]
];

var orderList = [];
var orderTotal =0;
var seqNo =1 ;