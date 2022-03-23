#include <bits/stdc++.h>
using namespace std;
int N,K,M;
int arr[1000][16];
bool vis[16];
int maxcnt=0;
void func(int n){
    if(n==M){
        int cnt=0;
        for(int i=0;i<N;i++){
            bool flag=false;
            for(int j=0;j<K;j++){
                if(!vis[j] && arr[i][j]>=5){
                    flag=true;
                }
            }
            if(flag)cnt++;
        }
        maxcnt=max(cnt,maxcnt);
        return;
    }
    for(int i=0;i<K;i++){
        if(vis[i])continue;
        vis[i]=true;
        func(n+1);
        vis[i]=false;
    }
}
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>K>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<K;j++){
            cin>>arr[i][j];
        }
    }
    func(0);
    cout<<maxcnt;
    return 0;
}