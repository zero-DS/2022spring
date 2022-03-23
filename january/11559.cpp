#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
char board[13][7];
bool visited[13][7];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool bbpop(int x, int y){
    queue< pair<int,int> > Q;
    queue< pair<int,int> > popcan;
    visited[x][y]=1;
    Q.push({x,y});
    popcan.push({Q.front().X,Q.front().Y});
    while(!Q.empty()){
        auto cur=Q.front();
        Q.pop();
        for(int d=0;d<4;d++){
            int nx=cur.X+dx[d];
            int ny=cur.Y+dy[d];
            if(nx<0 || ny<0 || nx>=12 || ny>=6)continue;
            if(visited[nx][ny]==1 || board[nx][ny]=='.')continue;
            if(board[cur.X][cur.Y]!=board[nx][ny])continue;
            visited[nx][ny]=1;
            popcan.push({nx,ny});
            Q.push({nx,ny});
        }
    }
    if(popcan.size()>=4){
        while(!popcan.empty()){
            board[popcan.front().X][popcan.front().Y]='.';
            popcan.pop();
        }
        return true;
    }
    else return false;
};
void godown(){
    for(int j=0;j<6;j++){
        char temp[13]={};
        int idx=11;
        for(int i=11;i>=0;i--){
            if(board[i][j]!='.'){
                temp[idx--]=board[i][j];
            }
        }
        for(int i=11;i>=0;i--){
            if(temp[i]=='\0')board[i][j]='.';
            else board[i][j]=temp[i];
        }
    }
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    for(int i=0;i<12;i++){
        for(int j=0;j<6;j++){
            board[i][j]=cin.get();
        }
        cin.get();
    }
    int ans=0;
    bool flag=true;
    while(flag){
        bool exist=false;
        for(int i=0;i<12;i++){
            for(int j=0;j<6;j++){
                if(board[i][j]!='.'){
                    fill(&visited[0][0],&visited[12][6],0);//초기화 까먹지 말기
                    if(bbpop(i,j))exist=true;
                }
            }
        }
        if(exist)ans++;
        else flag=false;
        godown();
    }
    cout<<ans;
    return 0;
}