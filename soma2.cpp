#include <bits/stdc++.h>
using namespace std;
int N,M,K;
vector<int> adj[101];
int like[101];
bool vis[101];
int main(void){
    cin>>N>>M>>K;
    for(int i=0;i<M;i++){
        int I,S;
        cin>>I>>S;
        like[I]=S;
    }
    for(int i=0;i<K;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int totalsum=0, totalnum=0;
    for(int i=1;i<=N;i++){
        if(vis[i])continue;
        queue<int> q;
        q.push(i);
        vis[i]=true;
        int validsum=0;
        int validnum=0;
        int friendnum=0;
        if(like[i]!=0){
            validsum+=like[i];
            validnum++;
        }
        friendnum++;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(auto nxt : adj[cur]){
                if(vis[nxt])continue;
                q.push(nxt);
                if(like[nxt]!=0){
                    validsum+=like[nxt];
                    validnum++;
                }
                friendnum++;
                vis[nxt]=true;
            }
        }
        if(validnum==0)continue;
        int avg=validsum/validnum;
        int total=validsum+avg*(friendnum-validnum);
        totalnum+=friendnum;
        totalsum+=total;
    }
    double avg=(double)totalsum/totalnum;
    if(!totalsum || !totalnum)avg=0;
    avg*=100;
    int multi=avg;
    avg=(double)multi/100;
    printf("%.2lf",avg);
    return 0;
}