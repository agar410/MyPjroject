#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int fn(int *arr,int len){
int l1=len/2;
int l2=len-l1;

if(len==1){
 return *arr;
}
int m1=fn(arr,l1);
int m2=fn(arr+l1,l2);

return m1+m2;

}
int main()
{
    srand((unsigned)time(NULL));
    const int n=10;
    int data[n];
    for(int i=0;i<n;i++){
        int a=20,b=50;
        data[i]=(rand()%(b-a+1))+a;
    }

    for(int i=0;i<10;+i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
    cout<<fn(data,n);
    return 0;
}
