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
 for(int i=0;i<n;i++){//��l�ƳB�z
    g.node(i).setd(-1);
    g.node(i).setp(-1);
 }

int now_node=0;
int a=0;

for(int l=0;l<n-1;l++){
     r[l]=now_node;
    vector<GNode> nb_u = g.outNeighbor(now_node);//���o��e�`�I���Ҧ��F�~
    g.node(now_node).setColor(BLACK);//�]�w���`�I�w�Q��춰�X��
    if(now_node!=0){//���o���`�I��d��
        a=g.node(now_node).getd();
    }

  for ( unsigned i=0; i<nb_u.size(); ++i ) {//�M�䦹�`�I���F�~�P�ɧ�s�L�̪�(�e�@�Ӹ`�I)p��d����
    int v = nb_u[i].getId();
    int Weight = nb_u[i].getWeight();//u-v�Z��
    int pre_d=g.node(v).getd();//�����F�~��d��

    if(g.node(v).getColor()!=BLACK){//��|�����L

    if(pre_d<=0||pre_d>Weight+a){//�P�_�O�_�ݧ�s�Z��
        g.node(v).setp(l);
        g.node(v).setd(Weight+a);//+a
        }
    }
 }
long int min_=9999;

 for(int i=0;i<n;i++){//�M��Z���̤p��
    if(g.node(i).getd()>=0 && g.node(i).getColor()!= BLACK ) {//d�����t�B�|���Q���
        if(g.node(i).getd()<=min_){
            min_=g.node(i).getd();//�]�̤p�Ȭ���e��d
        }
    }
 }

for(int i=0;i<n;i++){//�M��̵u�Z�����`�I
    if( g.node(i).getd()>=0 && g.node(i).getColor()!= BLACK ) {

    if(g.node(i).getd()==min_) {
            now_node=g.node(i).getId();//��s�U�@�Ӹ`�I
            break;
        }
    }
 }

 // O(n)
 for(int i=0;i<n;i++){//��X
    cout<<"     �`�I: "<<i <<" �e�@�`�I p= "<<g.node(i).getp()<<" d= "<<g.node(i).getd()<<endl;
 }
  cout<<"��ܪ��I: "<<now_node<<endl;

}
for(int i=0;i<n-1;i++){
    cout<<r[i]<<" ";
}
//g.show();
 return 0;
 }
