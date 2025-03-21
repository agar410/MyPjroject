<?php

$orderID=$_REQUEST["orderID"];
$orderList=$_REQUEST["orderList"];
$total = $_REQUEST["orderTotal"];

$aOrder = [ 'orderID' => $_REQUEST["orderID"],
            'orderList' =>$_REQUEST["orderList"],
            'total' => $_REQUEST["orderTotal"]
];

echo json_encode($aOrder, JSON_UNESCAPED_UNICODE);

$servername = "localhost";
$username = "breakfirst";
$password = "123456";
$dbname $username;

//
$conn = new mysqli($servername, $username, $password, $dbname);
//
if($conn->connect_error){
    die("Connection failed: " .$conn->connect_error);
}
//
$conn->query("SET NAMES UTF8;");

foreach ($orderList as $key => $item){
    $itemGroup =$item['styles'];
    $itemNo = $item['menu_index'];
    $itemName = $item['itemName'];
    $unitPrice = $item['unitPrice'];
    $qty = $item['qty'];

    $sql = "INSERT INTO `item_list` ( `order_id` , `item_group` , `item_no` , `item_name` ,`unit_ VALUES ( '$orderID','$itemGroup','$itemNo','$itemName', $unitPrice , $qty )";
    if($rs=== TRUE){
    echo "\n購買品項: " . $itemName . ":存入資料庫成功!\n";
    }else{
        echo "\n錯誤:" . $sql . "<br>" . $conn->error . "\n";
    }
}

$sql = "INSERT INTO `list_total` (`order_id`,`total` ) VALUES ('" . $orderID ."', $total );
$rs = $conn ->query($sql);
if ($rs === TRUE ){
    echo "\n訂單: " . $orderID . "總計: $" . $total . "存入資料庫成功!\n";
}else{
    echo "\n錯誤 " . $sql . "<br>" . $conn->error . "\n";
}

$conn->close();
/*
CREATE TABLE `breakfirst`.`item_list` 
(   `order_id` CHAR(12) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
    `item_group` TINYINT NULL ,
    `item_no` TINYINT NULL , 
    `item_name` VARCHAR(20) CHARACTER SET utf8 COLLATE utf8_general_ci NULL , 
    `unit_price` SMALLINT NULL , 
    `qty` TINYINT NULL 
) ENGINE = InnoDB CHARSET=utf8 COLLATE utf8_general_ci;


 CREATE TABLE `breakfirst`.`list_total` 
 ( `order_id` CHAR(12) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL , 
   `total` INT NOT NULL 
 ) ENGINE = InnoDB;
 */