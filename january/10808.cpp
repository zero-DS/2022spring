#include <bits/stdc++.h>
using namespace std;
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    string s;
    int alph[26]={0};
    cin>>s;
    for(int i=0;i<s.size();i++){
        alph[s[i]-97]++;
    }
    for(int i=0;i<26;i++){
        cout<<alph[i]<<' ';
    }
    return 0;
}