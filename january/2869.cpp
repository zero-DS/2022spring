#include <bits/stdc++.h>
using namespace std;
int main(void){
    int A,B,V;
    cin>>A>>B>>V;
    int days=1;
    V-=A;
    days+=V/(A-B);
    if(V%(A-B)!=0)days++;
    cout<<days;
    return 0;
}