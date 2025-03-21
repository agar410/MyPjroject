#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void bubbleSort_R(int arr[], int n, int len)
{
    if (n == 1){
        for(int i=0;i<len;i++){
            cout<<arr[i]<<" ";
        }
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }

    bubbleSort_R(arr, n - 1,  len);
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
    bubbleSort_R(data,10,10);
    //cout << "Hello world!" << endl;
    return 0;
}
