#include <bits/stdc++.h>
using namespace std;
int stairs[301];
int scores[301][3];
void dp(int cur){
    if(cur==1){
        scores[1][1]=stairs[1];
        return;
    }
    if(cur==2){
        scores[2][1]=stairs[2];
        scores[2][2]=scores[1][1]+stairs[2];
        return;
    }
    scores[cur][1]=max(scores[cur-2][1],scores[cur-2][2])+stairs[cur];
    scores[cur][2]=scores[cur-1][1]+stairs[cur];
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin>>N;
    for(int i=1;i<N+1;i++){
        cin>>stairs[i];
    }
    for(int i=1;i<N+1;i++){
        dp(i);
    }
    cout<<max(scores[N][1],scores[N][2]);
    return 0;
}