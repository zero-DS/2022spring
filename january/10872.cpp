#include <bits/stdc++.h>
using namespace std;
int facto(int n, int multi);
int main(void){
    int N;
    cin>>N;
    cout<<facto(N,1);

    return 0;
}
int facto(int n, int multi){
    if(n==1 || n==0)return multi;
    int m=facto(n-1,multi*n);
    return m;
}