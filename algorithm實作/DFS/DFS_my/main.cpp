 #include "../00_Libs/nsInclude.h"
 #include "../00_Libs/nsQueue.h"
 #include "../00_Libs/nsGraph.h"

 enum COLOR {
 WHITE=0, GRAY=1, BLACK=2
 };
 MyGraph g("../GraphDef-001.txt");
int go_graph_size=0;//�w�g�X�ݪ��I��
void dfs(MyGraph &mydfs , int next_node_id){//dfs�t��k
    DLL<GNode>& nb_u = g.adjList(next_node_id);//�a�J�U�Ӹ`�I

    if(go_graph_size==g.sizeV()-1){//������`�I�X�ݧ�
        mydfs.show();

    }
    g.node(next_node_id).setColor(BLACK);//�X�ݹL���

 for ( Node<GNode>* now=nb_u.getHead(); now!=NULL; now = now->getNext() ) { // �PBFS�X�ݬ۾F�`�I
    int v = now->getData().getId();
        if ( g.node(v).getColor()==WHITE ) {
        g.node(v).setColor(GRAY);
        mydfs.insertEdge(next_node_id,v, now->getData().getWeight());
        go_graph_size++;//�X�ݹL�F�A�X�ݼ�+1
        dfs(mydfs,v);//���jDFS
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
