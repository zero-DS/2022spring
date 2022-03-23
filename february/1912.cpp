#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int sum[100001];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        sum[i]=arr[i];
    }
    for(int i=1;i<=n;i++){
        sum[i]=max(sum[i],sum[i-1]+arr[i]);
    }
    cout<<*max_element(sum+1,sum+n+1);
    return 0;
}