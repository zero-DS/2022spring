#include <bits/stdc++.h>
using namespace std;
int N;
int board[2187][2187];
int cnt1=0,cnt2=0,cnt3=0;
bool checkValid(int a, int b, int size){
    int check=board[a][b];
    for(int i=a;i<a+size;i++){
        for(int j=b;j<b+size;j++){
            if(board[i][j]!=check)return false;
        }
    }
    return true;
};
void nine(int a, int b, int n){
    if(checkValid(a,b,n)){
        if(board[a][b]==-1)cnt1++;
        else if(board[a][b]==0)cnt2++;
        else if(board[a][b]==1)cnt3++;
    }
    else{
        for(int i=a;i<a+n;i+=n/3){
            for(int j=b;j<b+n;j+=n/3){
                nine(i,j,n/3);
            }
        }
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
    nine(0,0,N);
    cout<<cnt1<<'\n'<<cnt2<<'\n'<<cnt3;
    return 0;
}