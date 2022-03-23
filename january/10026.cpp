#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
char board[100][100]={0};
bool visNP[100][100]={0};
bool visSP[100][100]={0};
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
queue< pair<int,int> > Q1;
queue< pair<int,int> > Q2;
int N,ansN=0,ansS=0;
bool isRG(int nx, int ny, int curX, int curY){
    if(board[nx][ny]=='R' && board[curX][curY]=='G')return true;
    if(board[nx][ny]=='G' && board[curX][curY]=='R')return true;
    return false;
};
void BFS1(){
    while(!Q1.empty()){
        pair<int,int> cur=Q1.front();
        Q1.pop();
        for(int d=0;d<4;d++){
            int nx=dx[d]+cur.X;
            int ny=dy[d]+cur.Y;
            if(nx<0 || ny<0 || nx>=N || ny>=N)continue;
            if(visNP[nx][ny]==1 || board[nx][ny]!=board[cur.X][cur.Y])continue;
            visNP[nx][ny]=1;
            Q1.push({nx,ny});
        }
    }
};
void BFS2(){
    while(!Q2.empty()){
        pair<int,int> cur=Q2.front();
        Q2.pop();
        for(int d=0;d<4;d++){
            int nx=dx[d]+cur.X;
            int ny=dy[d]+cur.Y;
            if(nx<0 || ny<0 || nx>=N || ny>=N)continue;
            if(visSP[nx][ny]==1 || (board[nx][ny]!=board[cur.X][cur.Y] && !isRG(nx,ny,cur.X,cur.Y)))continue;
            visSP[nx][ny]=1;
            Q2.push({nx,ny});
        }
    }
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    cin.get();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            char temp=cin.get();
            board[i][j]=temp;
        }
        cin.get();
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visNP[i][j]==0){
                ansN++;
                visNP[i][j]=1;
                Q1.push({i,j});
                BFS1();
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visSP[i][j]==0){
                ansS++;
                visSP[i][j]=1;
                Q2.push({i,j});
                BFS2();
            }
        }
    }
    cout<<ansN<<' '<<ansS;
    return 0;
}