#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
queue< pair<int,int> > Q;
bool visited[500][500]={0};
int board[500][500]={0};
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int n,m;
int cnt=0,now=0,maxNow=0;
void BFS(){
    now=1;
    while(!Q.empty()){
        pair<int, int> cur=Q.front();
        Q.pop();
        for(int d=0;d<4;d++){
            int nx=cur.X+dx[d];
            int ny=cur.Y+dy[d];
            if(nx<0 || ny<0 || nx>=n || ny>=m)continue;
            if(visited[nx][ny]==1 || board[nx][ny]==0)continue;
            visited[nx][ny]=1;
            now++;
            Q.push({nx,ny});
        }
    }
    maxNow=max(now,maxNow);
    cnt++;
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]==0 && board[i][j]==1){
                visited[i][j]=1;
                Q.push({i,j});
                BFS();
            }
        }
    }
    cout<<cnt<<'\n'<<maxNow;
    return 0;
}