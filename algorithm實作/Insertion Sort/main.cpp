#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;


void insertion_sort_R(int a[],int N)
{
    if(a == NULL || N == 1)
        return;

    insertion_sort_R(a, N - 1);


    for(int i = N-1;i>0 && a[i] < a[i-1];i--)
        swap(a[i],a[i-1]);
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
    //insertion_sort_R(data,10,10);
    insertion_sort_R(data,10);
    for(int i=0;i<10;+i++){
        cout<<data[i]<<" ";
    }
    //cout << "Hello world!" << endl;
    return 0;
}
