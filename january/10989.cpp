#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N,temp;
    ios::sync_with_stdio(false);
    cin>>N;
    int sum[10001]={0};
    for(int i=0;i<N;i++){
        cin>>temp;
        sum[temp]++;
    }
    for(int i=1;i<10001;i++){
        for(int j=0;j<sum[i];j++)cout<<i<<'\n';
    }
    return 0;
}
