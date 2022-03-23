#include <bits/stdc++.h>
using namespace std;
queue< tuple<int,int,int> > Q;
bool maze[5][5][5];//1이 지나갈수있는 칸
bool tempmaze[5][5][5];//돌리고 순서바뀐 미로
bool tempfloor[5][5];
int visited[5][5][5];
int dirarr[5];
int heightarr[5];
bool heightvis[5];
int dx[6]={0,1,0,-1,0,0};
int dy[6]={1,0,-1,0,0,0};
int dz[6]={0,0,0,0,1,-1};
int mindist=99999;
void spin(int th, int mh, int dir){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            tempmaze[th][i][j]=maze[mh][i][j];
        }
    }
    while(dir--){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                tempfloor[i][j]=tempmaze[th][5-1-j][i];
            }
        }
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                tempmaze[th][i][j]=tempfloor[i][j];
            }
        }
    }
};
void BFS(){
    while(!Q.empty()){
        auto cur=Q.front();
        int cx,cy,cz;
        tie(cz,cx,cy)=cur;
        Q.pop();
        for(int d=0;d<6;d++){
            int nx=cx+dx[d];
            int ny=cy+dy[d];
            int nz=cz+dz[d];
            if(nx<0 || ny<0 || nz<0 || nx>=5 || ny>=5 || nz>=5)continue;
            if(visited[nz][nx][ny]!=0 || tempmaze[nz][nx][ny]==0)continue;
            visited[nz][nx][ny]=visited[cz][cx][cy]+1;
            if(nz==4 && nx==4 && ny==4)return;
            Q.push({nz,nx,ny});
        }
    }
};
void func(int n){
    if(n==5){
        for(int k=0;k<5;k++){
            spin(k,heightarr[k],dirarr[k]);//돌리기
        }
        if(tempmaze[0][0][0]==0)return;//시작점에서 출발을 못하는 경우
        fill(&visited[0][0][0],&visited[4][4][5],0);//초기화
        while(!Q.empty())Q.pop();//초기화
        visited[0][0][0]=1;
        Q.push({0,0,0});
        BFS();
        if(visited[4][4][4]!=0)mindist=min(mindist,visited[4][4][4]);
        
        return;
    }
    for(int i=0;i<4;i++){//돌리는방향네가지
        for(int j=0;j<5;j++){//층순서바꾸기
            if(heightvis[j]==false){
                heightvis[j]=true;
                dirarr[n]=i;
                heightarr[n]=j;
                func(n+1);
                heightvis[j]=false;
            }
        }
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    for(int k=0;k<5;k++){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                cin>>maze[k][i][j];
            }
        }
    }
    func(0);
    if(mindist!=99999)cout<<mindist-1;
    else cout<<-1;
    return 0;
}