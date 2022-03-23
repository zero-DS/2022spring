#include <bits/stdc++.h>
using namespace std;
int main(void){
    bool arr[10001]={1,1};
    for(int i=2;i<10001;i++){
        if(arr[i]==1)continue;
        for(int j=2;;j++){
            if(i*j>10000)break;
            arr[i*j]=1;
        }
    }
    int M,N;
    int sum=0,flag=0,min;
    cin>>M>>N;
    for(int i=M;i<=N;i++){
        if(arr[i]==0){
            sum+=i;
            if(flag==0){
                flag=1;
                min=i;
            }
        }
    }
    if(flag==0)cout<<-1;
    else cout<<sum<<'\n'<<min;
    return 0;
}