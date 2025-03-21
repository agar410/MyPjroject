#include <iostream>

using namespace std;

void move_(char a[], int k, int m)//將a[m]項移到最後一項，其他向前移一位
{
     char tmp=a[k];
     for(int i=k;i<m-1;i++)
         a[i]=a[i+1];
     a[m-1]=tmp;
}

void subset(char a[],int k,int m){
   if(k==m)
    for(int j=0;j<2;j++,k--)
   {
       for(int i=0;i<k-1;i++)
       {
           cout<<a[i]<<" ";
       }
       cout<<a[k-1];
       cout<<endl;
   }

   else {
    for(int i=0;i<m-k;i++)
    {
        subset(a,k+1,m-i);
        move_(a,k,m);
    }
   }
}
int main()
{   int m=5,k=0;
    char a[5]={'a','b','c','d','e'};
    subset(a,k,m);
    //cout << "Hello world!" << endl;
    return 0;
}
