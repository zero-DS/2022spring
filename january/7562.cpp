#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int visited[300][300];
int dx[8]={-2,-2,-1,-1,1,1,2,2};
int dy[8]={-1,1,-2,2,-2,2,-1,1};
int L;
int lx,ly;
queue< pair<int,int> > Q;
void BFS(){
    while(!Q.empty()){
        auto cur = Q.front();
        Q.pop();
        if(cur.X==lx && cur.Y==ly){
            cout<<visited[cur.X][cur.Y]-1<<'\n';
            return;
        }
        for(int d=0;d<8;d++){
            int nx=dx[d]+cur.X;
            int ny=dy[d]+cur.Y;
            if(nx<0 || ny<0 || nx>=L || ny>=L)continue;
            if(visited[nx][ny]>0)continue;
            visited[nx][ny]=visited[cur.X][cur.Y]+1;
            Q.push({nx,ny});
        }
    }
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int T,sx,sy;
    cin>>T;
    while(T--){
        cin>>L;
        cin>>sx>>sy;
        visited[sx][sy]=1;
        Q.push({sx,sy});
        cin>>lx>>ly;
        BFS();
        while(!Q.empty())Q.pop();
        fill(&visited[0][0],&visited[299][299],0);
    }
    return 0;
}