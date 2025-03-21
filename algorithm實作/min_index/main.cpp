#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int min_Index(int *arr,int len,int index){
    int left = len/2;
    int right = len-left;

    if(len == 1){
        return index;
    }

    int m1 = min_Index(arr,left,index);
    int m2 = min_Index(arr,right,index+left);

    if(arr[m1] <= arr[m2]){
        return m1;
    } else{
        return m2;
    }

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
    int l=n;
    cout<<"最小住標為:"<< min_Index(data,l,0) << endl;
    return 0;
}
