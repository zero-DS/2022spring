#include <bits/stdc++.h>
using namespace std;
char board[2187][2187];
void star(int i, int j, int n){
    if(n==1){
        board[i][j]='*';
        return;
    }
    int smallN=n/3;
    for(int k=0;k<3;k++){
        for(int l=0;l<3;l++){
            if(!(k==1 && l==1)){
                star(i+k*smallN,j+l*smallN,smallN);
            }
        }
    }
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin>>N;
    fill(&board[0][0],&board[N-1][N-1],' ');
    star(0,0,N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<board[i][j];
        }
        cout<<'\n';
    }
    return 0;
}