 #include "../00_Libs/nsInclude.h"
 #include "../00_Libs/nsQueue.h"
 #include "../00_Libs/nsGraph.h"

 enum COLOR {
 WHITE=0, GRAY=1, BLACK=2
 };
 MyGraph g("../GraphDef-001.txt");
int go_graph_size=0;//已經訪問的點數
void dfs(MyGraph &mydfs , int next_node_id){//dfs演算法
    DLL<GNode>& nb_u = g.adjList(next_node_id);//帶入下個節點

    if(go_graph_size==g.sizeV()-1){//當全部節點訪問完
        mydfs.show();

    }
    g.node(next_node_id).setColor(BLACK);//訪問過塗黑

 for ( Node<GNode>* now=nb_u.getHead(); now!=NULL; now = now->getNext() ) { // 同BFS訪問相鄰節點
    int v = now->getData().getId();
        if ( g.node(v).getColor()==WHITE ) {
        g.node(v).setColor(GRAY);
        mydfs.insertEdge(next_node_id,v, now->getData().getWeight());
        go_graph_size++;//訪問過了，訪問數+1
        dfs(mydfs,v);//遞迴DFS
    }

 }

    //node_o.getNode()
    //mydfs.node()
    //node_o.setColor(GRAY);
    //DLL<GNode>& nb_u = g.adjList(u);
}
int main()
 {
 //MyGraph g("../GraphDef-001.txt");

 /* BFS */
 int n = g.sizeV();
 MyGraph BFST(n, true);
 MyGraph DFST(n, true);
 MyQueue<int> q;
 //g.show();
 cout<<endl;
 int s=0;
 g.node(s).setColor(GRAY);
 dfs(DFST,0);
 /*
 q.push(s);

 while ( q.size()!=0 ) {
 int u = q.top();
 q.pop();


 DLL<GNode>& nb_u = g.adjList(u); // O(1)
 for ( Node<GNode>* now=nb_u.getHead(); now!=NULL; now = now->getNext() ) { // O(|Eu|)
    int v = now->getData().getId();
        if ( g.node(v).getColor()==WHITE ) {
        g.node(v).setColor(GRAY);
        q.push(v);
        BFST.insertEdge(u,v, now->getData().getWeight());
    }
 }
    g.node(u).setColor(BLACK);
 }
 BFST.show();
*/
 g.show();
 return 0;
 }
