#include <bits/stdc++.h>
using namespace std;
int main(void){
    int arr[15][14]={1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    for(int i=1;i<15;i++){
        for(int j=0;j<14;j++){
            if(j==0)arr[i][j]=1;
            else{
                arr[i][j]=arr[i][j-1]+arr[i-1][j];
            }
        }
    }
    int T,k,n;
    cin>>T;
    while(T--){
        cin>>k>>n;
        cout<<arr[k][n-1]<<'\n';
    }
    return 0;
}