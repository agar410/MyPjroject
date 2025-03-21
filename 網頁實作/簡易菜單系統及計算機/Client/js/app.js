function main()
{
$("#changeColor-tab").load("./Client/html/changeColor/index.html", changeColorMain);
$("#calcV1-tab").load("./Client/html/calcV1/index.html", calcV1Main);
$("#calcV2-tab").load("./Client/html/calcV2/index.html", calcV2Main);
$("#pos-tab").load("./Client/html/pos/index.html", posMain);
}

$(document).ready(main);