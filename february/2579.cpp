#include <bits/stdc++.h>
using namespace std;
int stairs[301];
int score[301];
void dp(int cur){
    if(cur==1){
        score[1]=stairs[1];
        return;
    }
    if(cur==2){
        score[2]=score[1]+stairs[2];
        return;
    }
    score[cur]=stairs[cur]+max(score[cur-2],score[cur-3]+stairs[cur-1]);
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
    cout<<score[N];
    return 0;
}