#include <bits/stdc++.h>
using namespace std;
int arr[100001][5];
int sum[100001][5];
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int tc=1;
    while(1){
        int row;
        cin>>row;
        if(row==0)break;
        for(int i=1;i<=row;i++){
            for(int j=1;j<=3;j++){
                cin>>arr[i][j];
                if(i==1){
                    if(j==1)sum[i][j]=1001;//맨위가운데에서 시작해야하므로 맨위왼쪽은 배제
                    else if(j==2)sum[i][j]=arr[i][j];
                    else if(j==3)sum[i][j]=arr[i][j]+arr[i][j-1];//맨위가운데 -> 맨위오른쪽경로가 최소일수도 있음
                    continue;
                }
                if(j==2)sum[i][j]=arr[i][j]+min({sum[i-1][j-1],sum[i-1][j],sum[i-1][j+1],sum[i][j-1]});
                else if(j==1)sum[i][j]=arr[i][j]+min(sum[i-1][j],sum[i-1][j+1]);
                else sum[i][j]=arr[i][j]+min({sum[i-1][j-1],sum[i-1][j],sum[i][j-1]});
            }
        }
        cout<<tc++<<". "<<sum[row][2]<<'\n';
    }
    return 0;
}