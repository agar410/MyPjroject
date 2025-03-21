var canvas = $("#myCanvas");
var ctx = canvas[0].getContext("2d"); //jquery寫法 物件要[0]捕捉
var x=canvas[0].width/2;
var y=canvas[0].height-30;
var dx=2;
var dy=-2;
var ballRadius = 10;

var score = 0;
var CumulativeScore=0;
var MaxScore=90;

var lives = 5;
//磚塊***********
var lv=1;
var brickRowCount = 3;
var brickColumnCount = 5;
var brickWidth = 75;
var brickHeight = 20;
var brickPadding = 10;
var brickOffsetTop = 30;
var brickOffsetLeft = 30;
var bricks = [];
for(c=0; c<brickColumnCount; c++) {
    bricks[c] = [];
    for(r=0; r<brickRowCount; r++) {
        bricks[c][r] = { x: 0, y: 0, status:lv };
    }
}
//*************/


var paddleHeight = 10;
var paddleWidth = 75;
var paddleX = (canvas[0].width-paddleWidth)/2;
var rightPressed = false;
var leftPressed = false;

var Dx = 0;
//監聽鍵盤按鍵
$(document).keydown(function(e){
    if(e.keyCode==39)
    rightPressed=true;
    else if(e.keyCode==37)
    leftPressed=true;  
});
$(document).keyup(function(e){
    if(e.keyCode==39)
    rightPressed=false;
    else if(e.keyCode==37)
    leftPressed=false;
});

$(document).mousemove(function(e){
    var relativeX = e.clientX - canvas[0].offsetLeft;
    if(relativeX > 0 && relativeX < canvas[0].width) {
        paddleX = relativeX - paddleWidth/2;
    }
});

const drawLives=(e)=>{
    ctx.font = "16px Arial";
    if(lives>3){
        ctx.fillStyle = "green";
        ctx.fillText("Lives: "+lives, canvas[0].width-65, 20);       
    }
    if(lives<=3&&lives>1){
        ctx.fillStyle = "orange";
        ctx.fillText("Lives: "+lives, canvas[0].width-65, 20);       
    }   
    if(lives==1){
        ctx.fillStyle = "red";
        ctx.fillText("Lives: "+lives, canvas[0].width-65, 20);       
    }    
};

const drawBall =(e)=>{//創造一顆球
    ctx.beginPath();
    ctx.arc(x, y, ballRadius, 0, Math.PI*2);
    ctx.fillStyle =  "rgb(255,165,0)";
    ctx.fill();
    ctx.closePath();

};

const drawPaddle=(e)=>{//創造球拍
    ctx.beginPath();
    ctx.rect(paddleX, canvas[0].height-paddleHeight, paddleWidth, paddleHeight);
    ctx.fillStyle = "#0095DD";
    ctx.fill();
    ctx.closePath(); 
};
const drawScore=(e)=>{
    ctx.font = "16px Arial";
    ctx.fillStyle = "#0095DD";
    ctx.fillText("Score: "+score, 8, 20);   
};

const drawCumulativeScore=(e)=>{
    ctx.font = "16px Arial";
    ctx.fillStyle = "orange";
    ctx.fillText("CumulativeScore: "+CumulativeScore, 90, 20);   
};

const drawLv=(e)=>{
    ctx.font = "16px Arial";
    if(lv<3){
        ctx.fillStyle = "orange";
        ctx.fillText("LV: "+lv, 280, 20);         
    }
    if(lv==3){
        ctx.fillStyle = "red";
        ctx.fillText("FinalLV: "+lv, 280, 20);
    }
};

const drawBricks=(e)=>{
    for(c=0; c<brickColumnCount; c++) {
        for(r=0; r<brickRowCount; r++) {
            if( bricks[c][r].status >= 1){
                var brickX = (c*(brickWidth+brickPadding))+brickOffsetLeft;
                var brickY = (r*(brickHeight+brickPadding))+brickOffsetTop;
                bricks[c][r].x = brickX;
                bricks[c][r].y = brickY;
                ctx.beginPath();
                ctx.rect(brickX, brickY, brickWidth, brickHeight);
                if( bricks[c][r].status == 3)
                ctx.fillStyle = "orange";                   
                if( bricks[c][r].status == 2)
                ctx.fillStyle = "green";               
                if( bricks[c][r].status == 1)
                ctx.fillStyle = "#0095DD";
                ctx.fill();
                ctx.closePath();
            }
        }
    }
};



const collisionDetection=(e)=>{
    for(c=0; c<brickColumnCount; c++) {
        for(r=0; r<brickRowCount; r++) {
            var b = bricks[c][r];
            if(b.status >= 1) {
                if(x > b.x && x < b.x+brickWidth && y > b.y && y < b.y+brickHeight) {
                    dy = -dy;
                    b.status -=1;

                    score++;
                    
                    if(score == brickRowCount*brickColumnCount*lv+CumulativeScore) {
                        CumulativeScore=score+CumulativeScore;
                        lv++;
                        alert("YOU WIN, GO TO NEXT LV");
                        nextLv();

                    } 
                    if(lv==3 && score==MaxScore){//無法獲勝
                        alert("YOU WIN, CONGRATULATIONS!");
                        restart();  
                    }                   
                }
            }
        }
    }
};

//下一關
const nextLv=(e)=>{
    x=canvas[0].width/2;
    y=canvas[0].height-30;
    paddleX = (canvas[0].width-paddleWidth)/2;
    dy=-2;
    //lives=3;
    rightPressed = false;
    leftPressed = false;  
    for(c=0; c<brickColumnCount; c++) {
        bricks[c] = [];
        for(r=0; r<brickRowCount; r++) {
            bricks[c][r] = { x: 0, y: 0, status:lv };
        }
    }    
};
//****************/重來
const restart=(e)=>{
    CumulativeScore=0;
    x=canvas[0].width/2;
    y=canvas[0].height-30;
    paddleX = (canvas[0].width-paddleWidth)/2;
    lv=1;
    Dx = 0;
    dy=-2;
    score=0;
    lives=5;
    rightPressed = false;
    leftPressed = false;  
    for(c=0; c<brickColumnCount; c++) {
        bricks[c] = [];
        for(r=0; r<brickRowCount; r++) {
            bricks[c][r] = { x: 0, y: 0, status:lv };
        }
    }
}
//****************/
const draw=(e)=>{//球和拍子的移動
    ctx.clearRect(0,0,canvas[0].width,canvas[0].height);
    drawBall();
    drawPaddle();
    drawScore();
    drawLv();
    drawCumulativeScore();
    drawLives();
    collisionDetection();
    drawBricks();
    if(x+dx>canvas[0].width-ballRadius||x+dx<ballRadius){
     dx=-dx;
    }//球
    if(y+dy<0){//ballRadius/2
     dy=-dy;
    }
    else if(y + dy > canvas[0].height-ballRadius) {
        if(x >= paddleX-ballRadius && x <= paddleX + paddleWidth+ballRadius) {
            Dx=paddleX-x+37;
            if(Dx<0){
                Dx=-1*Dx;
            }
            dy = -dy;
            //dx改角度
            if(Dx<10&&dx>0){
            dx=1;
            }
            if(Dx>=10&&Dx<24&&dx>0){
                dx=2;
                }            
             if(Dx>=24&&Dx<38&&dx>0){
                 dx=3;
                } 
            if(Dx<10&&dx<0){
                dx=-1;
                }
            if(Dx>=10&&Dx<24&&dx<0){
                dx=-2;
                }            
            if(Dx>=24&&Dx<38&&dx<0){
                dx=-3;
                }  
 /***********************************/                                          
        }
        else {
            lives--;
            if(!lives) {
                alert("GAME OVER");
                restart();
            }
            else {
                x = canvas[0].width/2;
                y = canvas[0].height-30;
                dx = 2;
                dy = -2;
                paddleX = (canvas[0].width-paddleWidth)/2;
                rightPressed = false;
                leftPressed = false;  
            }  
        }
    }


    if(rightPressed && paddleX < canvas[0].width-paddleWidth) {
        paddleX += 7;
    }//拍子
    else if(leftPressed && paddleX > 0) {
        paddleX -= 7;
    }//拍子
    x+=dx;
    y+=dy;
    requestAnimationFrame(draw);
};
//setInterval(draw, 10);//重複
//遊戲終止有問題
draw();
$(document).ready(drawLv);
$(document).ready(drawCumulativeScore);
$(document).ready(nextLv);
$(document).ready(drawLives);
$(document).ready(drawScore);
$(document).ready(collisionDetection);
$(document).ready(drawBricks);
$(document).ready(draw);
$(document).ready(drawBall);

