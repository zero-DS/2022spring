#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
char board[1000][1000];
int visitedF[1000][1000];
int visitedS[1000][1000];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
queue< pair<int,int> > QF;
queue< pair<int,int> > QS;
int h,w;
bool escapeFlag=false;
void BFSF(){
    while(!QF.empty()){
        auto cur=QF.front();
        QF.pop();
        for(int d=0;d<4;d++){
            int nx=dx[d]+cur.X;
            int ny=dy[d]+cur.Y;
            if(nx<0 || ny<0 || nx>=h || ny>=w)continue;
            if(visitedF[nx][ny]>0 || board[nx][ny]=='#')continue;
            visitedF[nx][ny]=visitedF[cur.X][cur.Y]+1;
            QF.push({nx,ny});
        }
    }
}
void BFSS(){
    while(!QS.empty()){
        auto cur=QS.front();
        QS.pop();
        for(int d=0;d<4;d++){
            int nx=dx[d]+cur.X;
            int ny=dy[d]+cur.Y;
            if(nx<0 || ny<0 || nx>=h || ny>=w){
                cout<<visitedS[cur.X][cur.Y]<<'\n';
                escapeFlag=true;
                return;
            }
            if(visitedS[nx][ny]>0 || board[nx][ny]=='#')continue;
            if(visitedF[nx][ny]!=0 && visitedF[nx][ny]<=visitedS[cur.X][cur.Y]+1)continue;
            visitedS[nx][ny]=visitedS[cur.X][cur.Y]+1;
            QS.push({nx,ny});
        }
    }
}
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--){
        cin>>w>>h;
        cin.get();
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                char temp=cin.get();
                board[i][j]=temp;
            }
            cin.get();
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(board[i][j]=='*'){
                    visitedF[i][j]=1;
                    QF.push({i,j});
                }
            }
        }
        BFSF();
        
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(board[i][j]=='@'){
                    visitedS[i][j]=1;
                    QS.push({i,j});
                    break;
                }
            }
        }
        escapeFlag=false;
        BFSS();
        
        if(!escapeFlag)cout<<"IMPOSSIBLE"<<'\n';
        fill(&board[0][0],&board[999][999],0);
        fill(&visitedF[0][0],&visitedF[999][999],0);
        fill(&visitedS[0][0],&visitedS[999][999],0);
        while(!QF.empty())QF.pop();
        while(!QS.empty())QS.pop();
    }
    return 0;
}