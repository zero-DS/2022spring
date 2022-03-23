#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N;
    cin>>N;
    double upbound=sqrt((double)N);
    if(N!=1){
        for(int i=2;i<=upbound;){
            if(N%i==0){
                N/=i;
                cout<<i<<'\n';
            }
            else i++;
        }
        if(N!=1)cout<<N;
    }
    return 0;
}