#include <bits/stdc++.h>
using namespace std;
char board[3072][6143];
void star(int i, int j, int n){
    if(n==3){
        board[i][j]='*';
        board[i+1][j-1]='*';
        board[i+1][j+1]='*';
        for(int k=j-2;k<=j+2;k++)board[i+2][k]='*';
        return;
    }
    star(i,j,n/2);
    star(i+n/2,j-(n/2),n/2);
    star(i+n/2,j+(n/2),n/2);
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int N,K;
    cin>>N;
    K=N/3;
    star(0,N-1,N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N*2-1;j++){
            if(board[i][j]=='*')cout<<'*';
            else cout<<' ';
        }
        cout<<'\n';
    }
    return 0;
}