#include <iostream>
using namespace std;
void comb(int [],int);
int arr[100],total=0;
int n,m;
int main(){
    cout<<"請輸入C(n,m)中的 n m :"<<endl;
   cin>>n>>m;
    for(int i=0;i<n;i++){
       arr[i]=i+1;
    }
  comb(arr,m);
  cout<<"共有: "<<total<<" 種組合。"<<endl;
  return 0;
}


void comb(int num[],int m){
   long long int a=1,b=1;
  for(int i=m+1;i<=n;i++){
    a=a*i;
  }
  for(int i=1;i<=n-m;i++){
    b=b*i;
  }
  int my_count=a/b;//組合數

  for(int w=0;w<my_count;w++){
        cout<<"{ ";
    for(int i=0;i<m;i++){
        cout<<num[i]<<" ";
        if(i==m-1){
            if(num[i]<n){
            num[i]+=1;}
            else{
                int pr=m-2,z=n-1;
                while(true){
                    if(num[pr]<z){
                      num[pr]+=1;
                      for(int k=pr+1;k<m;k++){
                        num[k]=num[k-1]+1;
                      }
                     break;
                    }
                    else{
                        pr--;
                        z--;
                    }

                }
            }

        }
    }
    cout<<"}"<<endl;
  }
  total=my_count;
}

