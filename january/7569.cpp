#include <bits/stdc++.h>
#include <tuple>
using namespace std;
int board[100][100][100];
int visited[100][100][100];
int dx[6]={0,0,0,1,0,-1};
int dy[6]={0,0,1,0,-1,0};
int dz[6]={1,-1,0,0,0,0};
queue< tuple<int,int,int> > Q;
int M,N,H;//가로 세로 높이
void BFS(){
    while(!Q.empty()){
        auto cur=Q.front();
        Q.pop();
        int cur1,cur2,cur3;
        tie(cur1,cur2,cur3)=cur;
        for(int d=0;d<6;d++){
            int nz=cur1+dz[d];
            int nx=cur2+dx[d];
            int ny=cur3+dy[d];
            if(nz<0 || nx<0 || ny<0 || nz>=H || nx>=N || ny>=M)continue;
            if(visited[nz][nx][ny]>0 || board[nz][nx][ny]==-1)continue;
            visited[nz][nx][ny]=visited[cur1][cur2][cur3]+1;
            Q.push({nz,nx,ny});
        }
    }
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int max=0;
    cin>>M>>N>>H;
    for(int i=0;i<H;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<M;k++){
                cin>>board[i][j][k];
            }
        }
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<M;k++){
                if(board[i][j][k]==1){
                    visited[i][j][k]=1;
                    Q.push({i,j,k});
                }
                if(board[i][j][k]==-1)visited[i][j][k]=-1;
            }
        }
    }
    BFS();
    for(int i=0;i<H;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<M;k++){
                if(visited[i][j][k]==0){
                    cout<<-1;
                    exit(0);
                }
                if(visited[i][j][k]>max)max=visited[i][j][k];
            }
        }
    }
    cout<<max-1;
    return 0;
}