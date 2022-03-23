#include <bits/stdc++.h>
using namespace std;
int alph[2][26]={0};
string a,b;
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int N,cnt=0;
    cin>>a>>b;
    for(int i=0;i<a.size();i++){
        alph[0][a[i]-'a']++;
    }
    for(int i=0;i<b.size();i++){
        alph[1][b[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(alph[0][i]!=alph[1][i]){
            cnt+=abs(alph[0][i]-alph[1][i]);
        }
    }
    cout<<cnt;
    return 0;
}
