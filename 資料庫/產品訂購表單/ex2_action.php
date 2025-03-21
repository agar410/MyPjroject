<html>
<head>
<style>
table { 
  border:1px solid #000; 
  font-family: 微軟正黑體; 
  font-size:16px; 
  width:200px;
  border:1px solid #000;
  text-align:center;
  border-collapse:collapse;
 
} 
th { 
  background-color: #009FCC;
  padding:10px;
  border:1px solid #000;
  color:#fff;
} 
td { 
  background-color: #fff;
  border:1px solid #000;
  color:#000;
  padding:5px;
  font-family: 微軟正黑體, "Microsoft JhengHei";
} 
body {
 background-color:hsl(89, 43%, 51%);
 color: #fff;
 /* font-family: "Note Sans TC",sans-serif; */

 font-family: 微軟正黑體, "Microsoft JhengHei";
}
</style>



</head>

<body>
<?php $ans=($_POST["top1"]+$_POST["but1"])*$_POST["high1"]/2?>
<table style="width:30%;font-family: Microsoft JhengHei" align="center" >
  <caption>梯型面積</caption>
  <tr>
    <th>   input   </th>
    <th>   ans   </th>
  </tr>

  <tr>
    <td>頂長</td>
    <td><?php echo $_POST["top1"]; ?></td>
  </tr>

  <tr>
    <td>底長</td>
    <td><?php echo $_POST["but1"]; ?></td>
  </tr>

  <tr>
    <td>高度</td>
    <td><?php echo $_POST["high1"]; ?></td>
  </tr>

  <tr>
    <td>面積:</td>
    <td><?php echo $ans?></td>
  </tr>
</table>
<!-- <br>
頂長 <?php echo $_POST["top1"]; ?><br>
底長 <?php echo $_POST["but1"]; ?><br>
高度 <?php echo $_POST["high1"]; ?><br>
面積:<?php echo $ans?> -->

</body>
</html>