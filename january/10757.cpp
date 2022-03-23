#include <bits/stdc++.h>
using namespace std;
int main(void){
    string a,b,result;
    cin>>a>>b;
    int lenA=a.size();
    int lenB=b.size();
    int carry=0;
    while(lenA>0 || lenB>0){
        int nA=0;
        if(lenA>0){
            nA=a[--lenA]-'0';
        }
        int nB=0;
        if(lenB>0){
            nB=b[--lenB]-'0';
        }
        int sum=nA+nB+carry;
        if(sum>=10){
            sum-=10;
            carry=1;
        }
        else{
            carry=0;
        }
        result+=(sum+'0');
    }
    if(carry!=0){
        result+='1';
    }
    reverse(result.begin(),result.end());
    cout<<result;
    return 0;
}