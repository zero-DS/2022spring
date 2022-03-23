#include <bits/stdc++.h>
using namespace std;
int board[1000][1000];
int visited[1000][1000][2];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
queue< tuple<int,int,bool> > Q;
int N,M;
void BFS(){
    while(!Q.empty()){
        auto cur=Q.front();
        Q.pop();
        int cur1,cur2;
        bool crash;
        tie(cur1,cur2,crash)=cur;
        if(cur1==N-1 && cur2==M-1){
            cout<<visited[cur1][cur2][crash];
            exit(0);
        }
        for(int d=0;d<4;d++){
            int nx=dx[d]+cur1;
            int ny=dy[d]+cur2;
            if(nx<0 || ny<0 || nx>=N || ny>=M)continue;
            if(visited[nx][ny][crash]>0)continue;
            if(board[nx][ny]==1 && crash==1)continue;
            if(board[nx][ny]==1 && crash==0){
                visited[nx][ny][1]=visited[cur1][cur2][0]+1;
                Q.push({nx,ny,1});
            }
            else{
                visited[nx][ny][crash]=visited[cur1][cur2][crash]+1;
                Q.push({nx,ny,crash});
            }
        }
    }
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M;
    cin.get();
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            board[i][j]=cin.get()-'0';
        }
        cin.get();
    }
    visited[0][0][0]=1;
    Q.push({0,0,0});
    BFS();
    cout<<-1;
    return 0;
}