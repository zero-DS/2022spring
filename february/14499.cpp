#include <bits/stdc++.h>
using namespace std;
int board[20][20];
int dice[4][3];
int temp[4][3];
int seq[2][6]={0,1,1,1,2,3,1,0,1,2,1,1};
int N,M,cx,cy,K,dir;
int roll(int dir){
    switch(dir){
        case 1 :{
            if(cy+1>=M)return -1;
            cy+=1;
            temp[0][1]=dice[0][1];
            temp[1][0]=dice[3][1];
            temp[1][1]=dice[1][0];
            temp[1][2]=dice[1][1];
            temp[2][1]=dice[2][1];
            temp[3][1]=dice[1][2];
            for(int i=0;i<6;i++){
                dice[seq[0][i]][seq[1][i]]=temp[seq[0][i]][seq[1][i]];
            }
            break;
        }
        case 2 :{
            if(cy-1<0)return -1;
            cy-=1;
            temp[0][1]=dice[0][1];
            temp[1][0]=dice[1][1];
            temp[1][1]=dice[1][2];
            temp[1][2]=dice[3][1];
            temp[2][1]=dice[2][1];
            temp[3][1]=dice[1][0];
            for(int i=0;i<6;i++){
                dice[seq[0][i]][seq[1][i]]=temp[seq[0][i]][seq[1][i]];
            }
            break;
        }
        case 3 :{
            if(cx-1<0)return -1;
            cx-=1;
            temp[0][1]=dice[1][1];
            temp[1][0]=dice[1][0];
            temp[1][1]=dice[2][1];
            temp[1][2]=dice[1][2];
            temp[2][1]=dice[3][1];
            temp[3][1]=dice[0][1];
            for(int i=0;i<6;i++){
                dice[seq[0][i]][seq[1][i]]=temp[seq[0][i]][seq[1][i]];
            }
            break;
        }
        case 4 :{
            if(cx+1>=N)return -1;
            cx+=1;
            temp[0][1]=dice[3][1];
            temp[1][0]=dice[1][0];
            temp[1][1]=dice[0][1];
            temp[1][2]=dice[1][2];
            temp[2][1]=dice[1][1];
            temp[3][1]=dice[2][1];
            for(int i=0;i<6;i++){
                dice[seq[0][i]][seq[1][i]]=temp[seq[0][i]][seq[1][i]];
            }
            break;
        }
        default :
            break;
    }
    if(board[cx][cy]!=0){
        dice[3][1]=board[cx][cy];//주사위 밑에 복사
        board[cx][cy]=0;
    }
    else board[cx][cy]=dice[3][1];//지도에 복사
    return dice[1][1];
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M>>cx>>cy>>K;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>board[i][j];
        }
    }
    for(int i=0;i<K;i++){
        cin>>dir;
        int top=roll(dir);
        if(top!=-1)cout<<top<<'\n';
    }
    return 0;
}