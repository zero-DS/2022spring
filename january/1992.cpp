#include <bits/stdc++.h>
using namespace std;
bool board[64][64];
bool isValid(int a, int b, int size){
    bool check=board[a][b];
    for(int i=a;i<a+size;i++){
        for(int j=b;j<b+size;j++){
            if(board[i][j]!=check)return false;
        }
    }
    return true;
};
void compress(int a, int b, int size){
    if(isValid(a,b,size)){
        cout<<board[a][b];
    }
    else{
        cout<<'(';
        compress(a,b,size/2);
        compress(a,b+size/2,size/2);
        compress(a+size/2,b,size/2);
        compress(a+size/2,b+size/2,size/2);
        cout<<')';
    }
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin>>N;
    cin.get();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            board[i][j]=cin.get()-'0';
        }
        cin.get();
    }
    compress(0,0,N);
    return 0;
}