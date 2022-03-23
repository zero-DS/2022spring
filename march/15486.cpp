#include <bits/stdc++.h>
using namespace std;
int T[1500001];
int P[1500001];
int profit[1500001];
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>T[i]>>P[i];
    }
    for(int i=0;i<N;i++){
        profit[i]=max(profit[i],profit[i-1]);
        if(i+T[i]>N)continue;
        profit[i+T[i]]=max(profit[i+T[i]],profit[i]+P[i]);
    }
    cout<<*max_element(profit,profit+N+1);
    return 0;
}