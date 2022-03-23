#include <bits/stdc++.h>
using namespace std;
int arr[1001][10];
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=0;j<10;j++){
            if(i==1)arr[i][j]=1;
            else{
                for(int k=0;k<=j;k++)arr[i][j]=(arr[i][j]+arr[i-1][k])%10007;
            }
        }
    }
    int ans=0;
    for(int i=0;i<10;i++)ans=(ans+arr[N][i])%10007;
    cout<<ans;
    return 0;
}