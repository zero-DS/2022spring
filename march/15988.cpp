#include <bits/stdc++.h>
using namespace std;
long long arr[1000001]={0,1,2,4};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin>>T;
    for(int i=4;i<=1000000;i++)arr[i]=(arr[i-1]+arr[i-2]+arr[i-3])%1000000009;
    while(T--){
        int tmp;
        cin>>tmp;
        cout<<arr[tmp]<<'\n';
    }

    return 0;
}