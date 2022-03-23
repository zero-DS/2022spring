#include <bits/stdc++.h>
using namespace std;
int arr[501][501];
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int N,M;
    int ans=0;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        arr[a][b]=1;
        arr[b][a]=1;
        if(a==1 || b==1){
            arr[a][b]=2;
            arr[b][a]=2;
            ans++;
        }
    }
    for(int i=1;i<=N;i++){
        if(arr[1][i]==2){
            for(int j=1;j<=N;j++){
                if(arr[i][j]==1 && arr[1][j]<2){
                    arr[1][j]=3;
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}