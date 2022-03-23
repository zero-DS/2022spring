#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int board[100][100];
bool visited[100][100];
queue< pair<int,int> > Q;
multiset<int> MS;
int M,N,K,area,cnt=0;
void paintBoard(int x1, int y1, int x2, int y2){
    for(int i=x1;i<x2;i++){
        for(int j=y1;j<y2;j++){
            board[i][j]=1;
        }
    }
};
void BFS(){
    while(!Q.empty()){
        auto cur=Q.front();
        Q.pop();
        for(int d=0;d<4;d++){
            int nx=dx[d]+cur.X;
            int ny=dy[d]+cur.Y;
            if(nx<0 || ny<0 || nx>=M || ny>=N)continue;
            if(visited[nx][ny]!=0 || board[nx][ny]==1)continue;
            area++;
            visited[nx][ny]=1;
            Q.push({nx,ny});
        }
    }
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int tempAX,tempAY,tempBX,tempBY;
    cin>>M>>N>>K;
    for(int i=0;i<K;i++){
        cin>>tempAY>>tempAX>>tempBY>>tempBX;
        paintBoard(tempAX,tempAY,tempBX,tempBY);
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(board[i][j]==0 && visited[i][j]==0){
                cnt++;
                area=1;
                visited[i][j]=1;
                Q.push({i,j});
                BFS();
                MS.insert(area);
            }
        }
    }
    cout<<cnt<<'\n';
    for(auto k : MS)cout<<k<<' ';
    return 0;
}