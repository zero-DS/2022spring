#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char board[1000][1000]={0};
int visited[1000][1000]={0};
queue< pair<int,int> > Q;
int R,C;
int maxVisited=0;
void BFS(){
    while(!Q.empty()){
        pair<int,int> cur=Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            int nx=cur.X+dx[i];
            int ny=cur.Y+dy[i];
            if(nx<0 || ny<0 || nx>=R || ny>=C){
                if(visited[cur.X][cur.Y]<0)continue;
                cout<<visited[cur.X][cur.Y];
                exit(0);
            }
            if(visited[nx][ny]>0 && visited[cur.X][cur.Y]<0){
                if(visited[nx][ny]>abs(visited[cur.X][cur.Y])+1 && visited[nx][ny]==maxVisited){
                    cout<<"IMPOSSIBLE";
                    exit(0);
                }
                else{
                    visited[nx][ny]=visited[cur.X][cur.Y]-1;
                    Q.push({nx,ny});
                    continue;
                }
            }
            if(visited[nx][ny]!=0 || board[nx][ny]!='.')continue;
            if(visited[cur.X][cur.Y]>0){
                visited[nx][ny]=visited[cur.X][cur.Y]+1;
                maxVisited=max(visited[nx][ny],maxVisited);
            }
            else visited[nx][ny]=visited[cur.X][cur.Y]-1;
            Q.push({nx,ny});
        }
    }
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    cin>>R>>C;
    cin.get();
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            char temp=cin.get();
            board[i][j]=temp;
        }
        cin.get();
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(board[i][j]=='J'){
                visited[i][j]=1;
                Q.push({i,j});
                break;
            }
        }
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(board[i][j]=='F'){
                visited[i][j]=-1;
                Q.push({i,j});
                break;
            }
        }
    }
    BFS();
    cout<<"IMPOSSIBLE";
    return 0;
}