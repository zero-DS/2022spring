#include <bits/stdc++.h>
using namespace std;
int getSec(char c);
int main(void){
    int sum=0;
    char c=cin.get();
    while(c!='\n'){
        sum+=getSec(c);
        c=cin.get();
    }
    cout<<sum;

    return 0;
}
int getSec(char c){
    if(c=='A'||c=='B'||c=='C') return 3;
    else if(c=='D'||c=='E'||c=='F') return 4;
    else if(c=='G'||c=='H'||c=='I') return 5;
    else if(c=='J'||c=='K'||c=='L') return 6;
    else if(c=='M'||c=='N'||c=='O') return 7;
    else if(c=='P'||c=='Q'||c=='R'||c=='S') return 8;
    else if(c=='T'||c=='U'||c=='V') return 9;
    else if(c=='W'||c=='X'||c=='Y'||c=='Z') return 10;
    else return 0;
}