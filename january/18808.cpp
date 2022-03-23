#include <bits/stdc++.h>
using namespace std;
int N,M,K,R,C;
bool board[40][40];
bool sticker[10][10];
void rotate(){
    bool temp[10][10];
    for(int i=0;i<C;i++){
        for(int j=0;j<R;j++){
            temp[i][j]=sticker[R-1-j][i];
        }
    }
    for(int i=0;i<C;i++){
        for(int j=0;j<R;j++){
            sticker[i][j]=temp[i][j];
        }
    }
    swap(R,C);
};
bool checkValid(int x, int y){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(board[x+i][y+j] && sticker[i][j])return false;
        }
    }//이 반복문이 제대로 끝났다면 스티커 붙이기 가능
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(sticker[i][j])board[x+i][y+j]=1;
        }
    }
    return true;
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M>>K;
    for(int k=0;k<K;k++){
        cin>>R>>C;
        for(int r=0;r<R;r++){
            for(int c=0;c<C;c++){
                cin>>sticker[r][c];
            }
        }
        bool flag=0;
        for(int r=0;r<4;r++){//돌리기
            for(int i=0;i<=N-R;i++){
                for(int j=0;j<=M-C;j++){
                    if(checkValid(i,j)){
                        flag=1;
                        break;
                    }
                }
                if(flag)break;
            }
            if(flag)break;
            rotate();
        }
    }
    int cnt=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(board[i][j])cnt++;
        }
    }
    cout<<cnt;
    return 0;
}