#include <bits/stdc++.h>
using namespace std;
int main(void){
    int M,N;
    cin>>M>>N;
    bool arr[1000001]={1,1};
    for(int i=2;i<=(int)sqrt(1000000.0);i++){
        for(int j=2;;j++){
            if(i*j>1000000)break;
            arr[i*j]=1;
        }
    }
    for(int i=M;i<=N;i++){
        if(arr[i]==0)cout<<i<<'\n';
    }
    return 0;
}