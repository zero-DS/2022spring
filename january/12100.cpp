#include <bits/stdc++.h>
using namespace std;
int board[20][20];
int rotated[20][20];
int board2[20][20];
int tiltarr[5];
int N,maxnum=0;
void rotate(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            rotated[i][j]=board2[N-1-j][i];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            board2[i][j]=rotated[i][j];
        }
    }
};
void tilt(int dir){
    int d=4-dir;
    while(dir--)rotate();
    for(int i=0;i<N;i++){
        int idx=0;
        int temp[20]={};
        for(int j=0;j<N;j++){//숫자들을 뭉치는 과정
            if(board2[i][j]==0)continue;
            if(temp[idx]==0){
                temp[idx]=board2[i][j];
            }
            else if(board2[i][j]==temp[idx]){
                temp[idx++]*=2;
            }
            else{
                temp[++idx]=board2[i][j];
            }
        }
        for(int j=0;j<N;j++){
            board2[i][j]=temp[j];
        }
    }
    while(d--)rotate();
};
void func(int n){
    if(n==5){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                board2[i][j]=board[i][j];
            }
        }
        for(int i=0;i<5;i++){
            tilt(tiltarr[i]);
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                maxnum=max(maxnum,board2[i][j]);
            }
        }
        return;
    }
    for(int i=0;i<4;i++){
        tiltarr[n]=i;
        func(n+1);
    }
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>board[i][j];
        }
    }
    func(0);
    cout<<maxnum;
    return 0;
}