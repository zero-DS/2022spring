#include <bits/stdc++.h>
using namespace std;
int fibo(int n);
int main(void){
    int n;
    cin>>n;
    cout<<fibo(n);
    return 0;
}
int fibo(int n){
    if(n==0)return 0;
    else if(n==1)return 1;
    return fibo(n-1)+fibo(n-2);
}