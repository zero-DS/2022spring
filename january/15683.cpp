#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int N,M,cctvnum=0,minblind=9999;
int board[8][8];
int temp[8][8];
vector< pair<int,int> > cctvs;
int dir[8];//동0 서1 남2 북3
void blind(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            temp[i][j]=board[i][j];
        }
    }
    for(int i=0;i<cctvnum;i++){
        int cctvkind=temp[cctvs[i].X][cctvs[i].Y];
        switch (cctvkind)
        {
        case 1:
            if(dir[i]==0){
                for(int j=cctvs[i].Y-1;j>=0;j--){
                    if(temp[cctvs[i].X][j]==0)temp[cctvs[i].X][j]=-1;
                    if(temp[cctvs[i].X][j]==6)break;
                }
            }
            else if(dir[i]==1){
                for(int j=cctvs[i].Y+1;j<M;j++){
                    if(temp[cctvs[i].X][j]==0)temp[cctvs[i].X][j]=-1;
                    if(temp[cctvs[i].X][j]==6)break;
                }
            }
            else if(dir[i]==2){
                for(int j=cctvs[i].X+1;j<N;j++){
                    if(temp[j][cctvs[i].Y]==0)temp[j][cctvs[i].Y]=-1;
                    if(temp[j][cctvs[i].Y]==6)break;
                }
            }
            else if(dir[i]==3){
                for(int j=cctvs[i].X;j>=0;j--){
                    if(temp[j][cctvs[i].Y]==0)temp[j][cctvs[i].Y]=-1;
                    if(temp[j][cctvs[i].Y]==6)break;
                }
            }
            break;
        case 2:
            if(dir[i]==0 || dir[i]==1){
                for(int j=cctvs[i].Y-1;j>=0;j--){
                    if(temp[cctvs[i].X][j]==0)temp[cctvs[i].X][j]=-1;
                    if(temp[cctvs[i].X][j]==6)break;
                }
                for(int j=cctvs[i].Y+1;j<M;j++){
                    if(temp[cctvs[i].X][j]==0)temp[cctvs[i].X][j]=-1;
                    if(temp[cctvs[i].X][j]==6)break;
                }
            }
            else if(dir[i]==2 || dir[i]==3){
                for(int j=cctvs[i].X+1;j<N;j++){
                    if(temp[j][cctvs[i].Y]==0)temp[j][cctvs[i].Y]=-1;
                    if(temp[j][cctvs[i].Y]==6)break;
                }
                for(int j=cctvs[i].X;j>=0;j--){
                    if(temp[j][cctvs[i].Y]==0)temp[j][cctvs[i].Y]=-1;
                    if(temp[j][cctvs[i].Y]==6)break;
                }
            }
            break;
        case 3:
            if(dir[i]==0){
                for(int j=cctvs[i].Y-1;j>=0;j--){
                    if(temp[cctvs[i].X][j]==0)temp[cctvs[i].X][j]=-1;
                    if(temp[cctvs[i].X][j]==6)break;
                }
                for(int j=cctvs[i].X;j>=0;j--){
                    if(temp[j][cctvs[i].Y]==0)temp[j][cctvs[i].Y]=-1;
                    if(temp[j][cctvs[i].Y]==6)break;
                }
            }
            else if(dir[i]==1){
                for(int j=cctvs[i].Y-1;j>=0;j--){
                    if(temp[cctvs[i].X][j]==0)temp[cctvs[i].X][j]=-1;
                    if(temp[cctvs[i].X][j]==6)break;
                }
                for(int j=cctvs[i].X+1;j<N;j++){
                    if(temp[j][cctvs[i].Y]==0)temp[j][cctvs[i].Y]=-1;
                    if(temp[j][cctvs[i].Y]==6)break;
                }
            }
            else if(dir[i]==2){
                for(int j=cctvs[i].X+1;j<N;j++){
                    if(temp[j][cctvs[i].Y]==0)temp[j][cctvs[i].Y]=-1;
                    if(temp[j][cctvs[i].Y]==6)break;
                }
                for(int j=cctvs[i].Y+1;j<M;j++){
                    if(temp[cctvs[i].X][j]==0)temp[cctvs[i].X][j]=-1;
                    if(temp[cctvs[i].X][j]==6)break;
                }
            }
            else if(dir[i]==3){
                for(int j=cctvs[i].X;j>=0;j--){
                    if(temp[j][cctvs[i].Y]==0)temp[j][cctvs[i].Y]=-1;
                    if(temp[j][cctvs[i].Y]==6)break;
                }
                for(int j=cctvs[i].Y+1;j<M;j++){
                    if(temp[cctvs[i].X][j]==0)temp[cctvs[i].X][j]=-1;
                    if(temp[cctvs[i].X][j]==6)break;
                }
            }
            break;
        case 4:
            if(dir[i]==0){
                for(int j=cctvs[i].Y+1;j<M;j++){
                    if(temp[cctvs[i].X][j]==0)temp[cctvs[i].X][j]=-1;
                    if(temp[cctvs[i].X][j]==6)break;
                }
                for(int j=cctvs[i].X+1;j<N;j++){
                    if(temp[j][cctvs[i].Y]==0)temp[j][cctvs[i].Y]=-1;
                    if(temp[j][cctvs[i].Y]==6)break;
                }
                for(int j=cctvs[i].X;j>=0;j--){
                    if(temp[j][cctvs[i].Y]==0)temp[j][cctvs[i].Y]=-1;
                    if(temp[j][cctvs[i].Y]==6)break;
                }
            }
            else if(dir[i]==1){
                for(int j=cctvs[i].Y-1;j>=0;j--){
                    if(temp[cctvs[i].X][j]==0)temp[cctvs[i].X][j]=-1;
                    if(temp[cctvs[i].X][j]==6)break;
                }
                for(int j=cctvs[i].X+1;j<N;j++){
                    if(temp[j][cctvs[i].Y]==0)temp[j][cctvs[i].Y]=-1;
                    if(temp[j][cctvs[i].Y]==6)break;
                }
                for(int j=cctvs[i].X;j>=0;j--){
                    if(temp[j][cctvs[i].Y]==0)temp[j][cctvs[i].Y]=-1;
                    if(temp[j][cctvs[i].Y]==6)break;
                }
            }
            else if(dir[i]==2){
                for(int j=cctvs[i].Y-1;j>=0;j--){
                    if(temp[cctvs[i].X][j]==0)temp[cctvs[i].X][j]=-1;
                    if(temp[cctvs[i].X][j]==6)break;
                }
                for(int j=cctvs[i].Y+1;j<M;j++){
                    if(temp[cctvs[i].X][j]==0)temp[cctvs[i].X][j]=-1;
                    if(temp[cctvs[i].X][j]==6)break;
                }
                for(int j=cctvs[i].X;j>=0;j--){
                    if(temp[j][cctvs[i].Y]==0)temp[j][cctvs[i].Y]=-1;
                    if(temp[j][cctvs[i].Y]==6)break;
                }
            }
            else if(dir[i]==3){
                for(int j=cctvs[i].Y-1;j>=0;j--){
                    if(temp[cctvs[i].X][j]==0)temp[cctvs[i].X][j]=-1;
                    if(temp[cctvs[i].X][j]==6)break;
                }
                for(int j=cctvs[i].Y+1;j<M;j++){
                    if(temp[cctvs[i].X][j]==0)temp[cctvs[i].X][j]=-1;
                    if(temp[cctvs[i].X][j]==6)break;
                }
                for(int j=cctvs[i].X+1;j<N;j++){
                    if(temp[j][cctvs[i].Y]==0)temp[j][cctvs[i].Y]=-1;
                    if(temp[j][cctvs[i].Y]==6)break;
                }
            }
            break;
        case 5:
            for(int j=cctvs[i].Y-1;j>=0;j--){
                if(temp[cctvs[i].X][j]==0)temp[cctvs[i].X][j]=-1;
                if(temp[cctvs[i].X][j]==6)break;
            }
            for(int j=cctvs[i].Y+1;j<M;j++){
                if(temp[cctvs[i].X][j]==0)temp[cctvs[i].X][j]=-1;
                if(temp[cctvs[i].X][j]==6)break;
            }
            for(int j=cctvs[i].X+1;j<N;j++){
                if(temp[j][cctvs[i].Y]==0)temp[j][cctvs[i].Y]=-1;
                if(temp[j][cctvs[i].Y]==6)break;
            }
            for(int j=cctvs[i].X;j>=0;j--){
                if(temp[j][cctvs[i].Y]==0)temp[j][cctvs[i].Y]=-1;
                if(temp[j][cctvs[i].Y]==6)break;
            }
            break;
        default:
            break;
        }
    }
    int cnt=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(temp[i][j]==0)cnt++;
        }
    }
    minblind=min(minblind,cnt);
};
void func(int n){
    if(n==cctvnum){
        blind();
        return;
    }
    for(int j=0;j<4;j++){
        dir[n]=j;
        func(n+1);
    }
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>board[i][j];
            if(board[i][j]>=1 && board[i][j]<=5){
                cctvs.push_back({i,j});
                cctvnum++;
            }
        }
    }
    func(0);
    cout<<minblind;
    return 0;
}