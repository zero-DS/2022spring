#include <bits/stdc++.h>
using namespace std;
int arr[1003];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    arr[1]=1;
    arr[2]=3;
    for(int i=3;i<n+1;i++){
        arr[i]=(arr[i-1]+arr[i-2]*2)%10007;
    }
    cout<<arr[n];
    return 0;
}