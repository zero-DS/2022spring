#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long A,B,C;
    cin>>A>>B>>C;
    long long result=A/(C-B)+1;
    if(B>=C)result=-1;
    cout<<result;
    return 0;
}