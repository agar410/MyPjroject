 #include "../00_Libs/nsInclude.h"
 #include "../00_Libs/nsStack.h"
 #include "../00_Libs/nsGraph.h"

 enum COLOR {
 WHITE=0, GRAY=1, BLACK=2
 };
 MyGraph g("../GraphDef-001.txt");

 int main()
 {
 /* BFS */
 int n = g.sizeV();
 int r[n]={0};
 for(int i=0;i<n;i++){//初始化處理
    g.node(i).setd(-1);
    g.node(i).setp(-1);
 }

int now_node=0;
int a=0;

for(int l=0;l<n-1;l++){
     r[l]=now_node;
    vector<GNode> nb_u = g.outNeighbor(now_node);//取得當前節點的所有鄰居
    g.node(now_node).setColor(BLACK);//設定此節點已被選到集合中
    if(now_node!=0){//取得此節點的d值
        a=g.node(now_node).getd();
    }

  for ( unsigned i=0; i<nb_u.size(); ++i ) {//尋找此節點的鄰居同時更新他們的(前一個節點)p跟d的值
    int v = nb_u[i].getId();
    int Weight = nb_u[i].getWeight();//u-v距離
    int pre_d=g.node(v).getd();//取的鄰居的d值

    if(g.node(v).getColor()!=BLACK){//當尚未走過

    if(pre_d<=0||pre_d>Weight+a){//判斷是否需更新距離
        g.node(v).setp(l);
        g.node(v).setd(Weight+a);//+a
        }
    }
 }
long int min_=9999;

 for(int i=0;i<n;i++){//尋找距離最小值
    if(g.node(i).getd()>=0 && g.node(i).getColor()!= BLACK ) {//d不為負且尚未被選擇
        if(g.node(i).getd()<=min_){
            min_=g.node(i).getd();//設最小值為當前的d
        }
    }
 }

for(int i=0;i<n;i++){//尋找最短距離的節點
    if( g.node(i).getd()>=0 && g.node(i).getColor()!= BLACK ) {

    if(g.node(i).getd()==min_) {
            now_node=g.node(i).getId();//更新下一個節點
            break;
        }
    }
 }

 // O(n)
 for(int i=0;i<n;i++){//輸出
    cout<<"     節點: "<<i <<" 前一節點 p= "<<g.node(i).getp()<<" d= "<<g.node(i).getd()<<endl;
 }
  cout<<"選擇的點: "<<now_node<<endl;

}
for(int i=0;i<n-1;i++){
    cout<<r[i]<<" ";
}
//g.show();
 return 0;
 }
