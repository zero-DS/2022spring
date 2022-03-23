#include <bits/stdc++.h>
using namespace std;
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int arr[2][7]={0};
    int N,K,tempS,tempY;
    int ans=0;
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>tempS>>tempY;
        arr[tempS][tempY]++;
    }
    for(int i=1;i<=6;i++){
        ans+=arr[0][i]/K;
        if(arr[0][i]%K!=0)ans++;
        ans+=arr[1][i]/K;
        if(arr[1][i]%K!=0)ans++;
    }
    cout<<ans;
    return 0;
}