#include <bits/stdc++.h>
using namespace std;
long long arr[91];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin>>N;
    arr[1]=1;
    arr[2]=1;
    for(int i=3;i<N+1;i++)arr[i]=arr[i-1]+arr[i-2];
    cout<<arr[N];
    return 0;
}