#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int sum[1001];
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
        sum[i]=arr[i];
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<i;j++){
            if(arr[j]<arr[i])sum[i]=max(sum[i],sum[j]+arr[i]);
        }
    }
    cout<<*max_element(sum+1,sum+N+1);
    return 0;
}