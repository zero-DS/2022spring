#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int board[25][25];
bool visited[25][25];
queue< pair<int,int> > Q;
multiset<int> S;
int N,cnt=0,bldg=0;
void BFS(){
    while(!Q.empty()){
        auto cur=Q.front();
        Q.pop();
        for(int d=0;d<4;d++){
            int nx=dx[d]+cur.X;
            int ny=dy[d]+cur.Y;
            if(nx<0 || ny<0 || nx>=N || ny>=N)continue;
            if(visited[nx][ny]==1 || board[nx][ny]==0)continue;
            cnt++;
            visited[nx][ny]=1;
            Q.push({nx,ny});
        }
    }
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    cin.get();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            board[i][j]=cin.get()-'0';
        }
        cin.get();
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i][j]==1 && visited[i][j]==0){
                cnt=1;
                bldg++;
                visited[i][j]=1;
                Q.push({i,j});
                BFS();
                S.insert(cnt);
            }
        }
    }
    cout<<bldg<<'\n';
    for(auto k : S)cout<<k<<'\n';
    return 0;
}