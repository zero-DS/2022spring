#include <bits/stdc++.h>
using namespace std;
int arr[1000];
void dp(int cur){
    if(cur==0){
        arr[cur]=1;
        return;
    }
    if(cur==1){
        arr[cur]=2;
        return;
    }
    arr[cur]=(arr[cur-1]+arr[cur-2])%10007;
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)dp(i);
    cout<<arr[n-1];
    return 0;
}