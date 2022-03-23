#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int board[100][100]={0};
int visited[100][100]={0};
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int N,M;
queue< pair<int,int> > Q;
void BFS(){
    while(!Q.empty()){
        pair<int,int> cur=Q.front();
        Q.pop();
        for(int d=0;d<4;d++){
            int nx=cur.X+dx[d];
            int ny=cur.Y+dy[d];
            if(nx<0 || ny<0 || nx>=N || ny>=M)continue;
            if(visited[nx][ny]!=0 || board[nx][ny]==0)continue;
            visited[nx][ny]=visited[cur.X][cur.Y]+1;
            Q.push({nx,ny});
        }
    }
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int temp;
    cin>>N>>M;
    cin.get();
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            temp=cin.get();
            board[i][j]=temp-'0';
        }
        cin.get();
    }
    visited[0][0]=0;
    Q.push({0,0});
    BFS();
    cout<<visited[N-1][M-1]+1;
    return 0;
}