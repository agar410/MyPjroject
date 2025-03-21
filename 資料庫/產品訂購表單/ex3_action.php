<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">

    <title>Document</title>
<style>
.error {color: #FF0000;}
input[type=text] {
              width: 25%;
              padding: 12px 20px;
              margin: 8px 0;
              box-sizing: border-box;
            }
div {
    background-color:#fefbd8;
    color: #000;
    /* font-family: "Note Sans TC",sans-serif; */
   
    font-family: 微軟正黑體, "Microsoft JhengHei";
   }
body {
 background-color:hsl(89, 43%, 51%);
 color: #fff;
 /* font-family: "Note Sans TC",sans-serif; */

 font-family: 微軟正黑體, "Microsoft JhengHei";
}
table { 
  border:1px solid #000; 
  font-family: 微軟正黑體; 
  font-size:16px; 
  width:200px;
  border:1px solid #000;
  text-align:center;
  border-collapse:collapse;
  background-color: #fff;
  color:#000;
} 
th { 
  background-color: #009FCC;
  padding:10px;
  border:1px solid #000;
  color:#fff;
} 
td { 
  border:1px solid #000;
  padding:5px;
} 
</style>

</head>

<body>

   <?php
    $showform = true;
    $error = "";
    $error1 = "";
    $msg = "";
    $product ="";
    $payWay="";
    // $name = $_POST["Name"];
    // $username = $_POST["UserName"];
    // $comment = $_POST["comment"];

    if ( isset($_POST["Reg"]) ) {
        // 取得表單欄位值
        $name = $_POST["Name"];
        $username = $_POST["UserName"];
        $comment = $_POST["comment"];
        // 檢查帳號欄位是否有輸入資料
        
        if (empty($name)) {
        // 欄位沒填
        $error = "姓名欄位空白<br/>";
        }
        else {
            if (empty($username)) {
                // 欄位沒填
                $error = "手機欄位空白<br/>";    
                }else{
                    $showform = false;
                    $webs=$_POST["Webs"];
                    foreach($webs as $value){
                        switch(trim($value)){
                            case "w1":
                            $product = "iPad";break;
                
                            case "w2":
                            $product ="iPhone";break;
                            case "w3":
                            $product = "HTC";break;
                            case "w4":
                            $product = "Samsong";break;                                    
                        }
                    }   
                    $gender=$_POST["Gender"];
                    switch(strtoupper($gender)){
                        case "MALE":
                        $payWay="貨到付款"; break;
                        case "FEMALE":
                        $payWay="ATM"; break;
                    }   
                    if(empty($comment)){
                      $comment="無";
                    }


                    // print "$name<br>";
                    // print "$username<br>";
                    // print "$product<br>";
                    // print "$payWay<br>";
                    // print "$comment<br>"  ; 

                }


        }
  
       }    


   ?>

<?php if ( $showform ) { // 顯示網頁表單
?>
<div  style="color:red;width:490px;margin:0px auto;border:1px #cccccc dashed;" align="center" >
<?php echo $error ?></div>
<form action="ex3_action.php" align="center" method="post">
<h3 style="font-family:Microsoft JhengHei;">訂貨系統</h3>  
<div style="width:490px;height:500px;border:3px #cccccc dashed;margin:0px auto;" >
姓名: <input type="text" name="Name" size ="10"
 value="<?php echo $name ?>"/>
 <span class="error">*</span><br/>
手機: <input type="text" name="UserName" size="10"
 value="<?php echo $username ?>"/>
 <span class="error">*</span><br/><br>
 產品 <br>
<select name="Webs[]" size="4" multiple="True">
    <option value="w1" selected="True">iPad</option>
    <option value="w2">iPhone</option>
    <option value="w3">HTC</option>
    <option value="w4">Samsong</option>
</select>
<br>
付款方式: <br>
<input type="radio" name="Gender" value="male" checked="True">貨到付款<br>
<input type="radio" name="Gender" value="female" >ATM <br> <br>
 地址 <textarea name="comment" rows="2" cols="40"></textarea>
  <br><br>
<input type="submit" name="Reg" value="送出"/>
</div>

</form>
<?php
} else{
?> 
<table style="width:30%" align="center" >
  <caption>訂單</caption>
  <tr>
    <th>   訂單項目  </th>
    <th>   客戶資料   </th>
  </tr>

  <tr>
    <td>名字</td>
    <td><?php print "$name<br>"; ?></td>
  </tr>

  <tr>
    <td>手機</td>
    <td><?php print "$username<br>"; ?></td>
  </tr>

  <tr>
    <td>產品</td>
    <td><?php print "$product<br>"; ?></td>
  </tr>

  <tr>
    <td>付款方式:</td>
    <td><?php  print "$payWay<br>";?></td>
  </tr>

  <tr>
    <td>地址:</td>
    <td><?php  print "$comment<br>"  ;?></td>
  </tr>
</table>

<?php
}?>
</body>
</html>