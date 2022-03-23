#include <bits/stdc++.h>
using namespace std;
int wine[10010];
int sum[10010][3];//[i][0]:i를 선택x [i][1]:i를 선택 [i][2]:i,i-1을 선택
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=3;i<n+3;i++){
        cin>>wine[i];
        sum[i][0]=max({sum[i-1][0],sum[i-1][1],sum[i-1][2]});
        sum[i][1]=wine[i]+sum[i-1][0];
        sum[i][2]=wine[i]+wine[i-1]+sum[i-2][0];
    }
    int ans=0;
    for(int i=3;i<n+3;i++){
        for(int j=0;j<3;j++){
            ans=max(ans,sum[i][j]);
        }
    }
    cout<<ans;
    return 0;
}