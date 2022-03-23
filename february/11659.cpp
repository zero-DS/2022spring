#include <bits/stdc++.h>
using namespace std;
int sum[100001];
int num[100001];
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int N,M;
    cin>>N>>M;
    for(int i=1;i<N+1;i++){
        cin>>num[i];
        sum[i]=sum[i-1]+num[i];
    }
    for(int i=0;i<M;i++){
        int tmp1,tmp2;
        cin>>tmp1>>tmp2;
        cout<<sum[tmp2]-sum[tmp1-1]<<'\n';
    }

    return 0;
}