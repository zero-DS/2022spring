#include <bits/stdc++.h>
using namespace std;
int dp[101][12];
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=10;j++){
            if(i==1 && j!=1)dp[i][j]=1;
            else{
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%1000000000;
            }
        }
    }
    int sum=0;
    for(int i=1;i<=10;i++){
        sum=(sum+dp[N][i])%1000000000;
    }
    cout<<sum;
    return 0;
}