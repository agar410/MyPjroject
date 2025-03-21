#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;


typedef unsigned long DWORD;


void SubSet(int arr[],int n)
{
    DWORD i,j,total,mask;
    if (n > 30)
    {
        cout<<n<<"too big"<<endl;
        return ;
    }

    total= (1 << n); //total subset
    for (j=0; j < total; j++)//其中一個子集
    {

        cout<<"{ ";

        i = 0;
        mask = j;
        while (mask > 0)//mask最後一位非0輸出
        {
            if (mask & 1)
               cout<<arr[i]<<" ";
            mask >>= 1;//右移一位
            i++;
        }
        cout<<"}"<<endl;

    }


}


int main()
{
    srand((unsigned)time(NULL));
    const int n=3;
    int data[n];
    for(int i=0;i<n;i++){
        int a=20,b=50;
        data[i]=(rand()%(b-a+1))+a;
    }
    for(int i=0;i<n;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;

    SubSet(data, n);

    return 0;
}
