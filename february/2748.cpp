#include <bits/stdc++.h>
using namespace std;
long long fib[91]={0,1,1};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=3;i<=n;i++)fib[i]=fib[i-1]+fib[i-2];
    cout<<fib[n];
    return 0;
}