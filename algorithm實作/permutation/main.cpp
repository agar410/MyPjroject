#include <iostream>
#include <algorithm>
using namespace std;


int my_next_permutation(int *Strat, int *End)
{
    int *i=Strat, *j, *k;
    if (i==End || ++i==End) return 0;
    for (i=End-1; i!=Strat;) {
        j = i--;
        if (!(*i < *j)) continue;

        for (k=End; !(*i < *(--k)););
        iter_swap(i,k);

        reverse(j,End);
        return 1;
    }

    reverse(Strat,End);
    return 0;
}

int main()
{
    int a[3]={1,2,3};
    int  b[4]={1,2,3,4};
 /*   for(int i=0;i<6;i++){
        next_permutation(a,a+3);
      for(int j=0;j<3;j++){
        cout<<a[j]<<" ";
      }
      cout<<endl;
    }*/

    for(int i=0;i<24;i++){
        my_next_permutation(b,b+4);
        cout<<"{ ";
      for(int j=0;j<4;j++){
        cout<<b[j]<<" ";
      }
      cout<<"}";
      cout<<endl;
    }
    return 0;
}
