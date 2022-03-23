#include <bits/stdc++.h>
using namespace std;
int house[1000][3];
int arr[1000][3];//0은 빨강 1은 초록 2는 파랑
void dp(int cur){
    if(cur==0){
        arr[cur][0]=house[cur][0];
        arr[cur][1]=house[cur][1];
        arr[cur][2]=house[cur][2];
        return;
    }
    arr[cur][0]=min(arr[cur-1][1],arr[cur-1][2])+house[cur][0];
    arr[cur][1]=min(arr[cur-1][0],arr[cur-1][2])+house[cur][1];
    arr[cur][2]=min(arr[cur-1][1],arr[cur-1][0])+house[cur][2];
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++){
            cin>>house[i][j];
        }
    }
    for(int i=0;i<N;i++)dp(i);
    cout<<min(min(arr[N-1][0],arr[N-1][1]),arr[N-1][2]);
    return 0;
}