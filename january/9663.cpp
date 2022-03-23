#include <bits/stdc++.h>
using namespace std;
bool visited1[14];//열이 퀸에 의해 점거되고 있는가
bool visited2[27];//오른쪽 위 대각선은 퀸에 의해 점거되고 있는가
bool visited3[27];//왼쪽 위 대각선은 퀸에 의해 점거되고 있는가
int N,cnt=0;
void NQueen(int n){//퀸은 각 행마다 하나씩 존재하므로 n은 n번째 행을 뜻함, 0번째 행부터 쭉쭉 내려가기
    if(n==N){
        cnt++;
        return;
    }
    for(int i=0;i<N;i++){//열마다 퀸을 새로 둘 수 있는지 확인
        if(visited1[i]==false && visited2[i+n]==false && visited3[i-n+N-1]==false){
            visited1[i]=true;
            visited2[i+n]=true;
            visited3[i-n+N-1]=true;
            NQueen(n+1);
            visited1[i]=false;
            visited2[i+n]=false;
            visited3[i-n+N-1]=false;
        }
    }
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    NQueen(0);
    cout<<cnt;
    return 0;
}