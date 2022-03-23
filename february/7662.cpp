#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
bool visited[1000000];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    priority_queue< pair<int,int> > maxq;
    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > minq;
    int T;
    cin>>T;
    while(T--){
        int k;
        cin>>k;
        for(int i=0;i<k;i++){
            char cmd;
            int cmdnum;
            cin>>cmd;
            if(cmd=='I'){
                cin>>cmdnum;
                maxq.push({cmdnum,i});
                minq.push({cmdnum,i});
                visited[i]=true;
            }
            else if(cmd=='D'){
                cin>>cmdnum;
                if(cmdnum==1){
                    while(!maxq.empty() && !visited[maxq.top().Y]){
                        maxq.pop();
                    }
                    if(maxq.empty())continue;
                    visited[maxq.top().Y]=false;
                    maxq.pop();
                }
                else if(cmdnum==-1){
                    while(!minq.empty() && !visited[minq.top().Y]){
                        minq.pop();
                    }
                    if(minq.empty())continue;
                    visited[minq.top().Y]=false;
                    minq.pop();
                }
            }
        }
        while(!maxq.empty() && !visited[maxq.top().Y]){
            maxq.pop();
        }
        while(!minq.empty() && !visited[minq.top().Y]){
            minq.pop();
        }
        if(minq.empty() || maxq.empty())cout<<"EMPTY"<<'\n';
        else cout<<maxq.top().X<<' '<<minq.top().X<<'\n';
        while(!maxq.empty())maxq.pop();
        while(!minq.empty())minq.pop();
        fill(visited,visited+1000000,0);
    }
    return 0;
}