#include <bits/stdc++.h>
using namespace std;
int arr[1000001]={0,1,2};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin>>N;
    for(int i=3;i<=N;i++)arr[i]=(arr[i-1]+arr[i-2])%15746;
    cout<<arr[N];
    return 0;
}