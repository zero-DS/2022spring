#include <bits/stdc++.h>
using namespace std;
long long padoban[101]={0,1,1,1,2,2};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin>>T;
    for(int i=6;i<=100;i++){
        padoban[i]=padoban[i-1]+padoban[i-5];
    }
    while(T--){
        int N;
        cin>>N;
        cout<<padoban[N]<<'\n';
    }
    return 0;
}