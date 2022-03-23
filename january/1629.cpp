#include <bits/stdc++.h>
using namespace std;
long long multi(int a, int b, int c){
    if(b==1)return a%c;
    long long val=multi(a,b/2,c);
    val=val*val%c;
    if(b%2==1)return val*a%c;
    else return val;
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int A,B,C;
    cin>>A>>B>>C;
    cout<<multi(A,B,C);
    return 0;
}