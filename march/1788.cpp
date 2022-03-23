#include <bits/stdc++.h>
using namespace std;
long long fibo[1000001]={0,1,1};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=3;i<=abs(n);i++)fibo[i]=(fibo[i-1]+fibo[i-2])%1000000000;
    if(n!=0){
        if(n<0 && abs(n)%2==0)cout<<-1<<'\n';
        else cout<<1<<'\n';
    }
    else cout<<n<<'\n';
    cout<<fibo[abs(n)];
    return 0;
}