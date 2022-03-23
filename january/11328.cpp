#include <bits/stdc++.h>
using namespace std;
bool check();
int alph[2][26]={0};
string a,b;
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a>>b;
        if(check())cout<<"Possible"<<'\n';
        else cout<<"Impossible"<<'\n';
    }
    return 0;
}
bool check(){
    fill(alph[0],alph[0]+26,0);
    fill(alph[1],alph[1]+26,0);
    if(a.size()!=b.size())return false;
    for(int i=0;i<a.size();i++){
        alph[0][a[i]-'a']++;
        alph[1][b[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(alph[0][i]!=alph[1][i])return false;
    }
    return true;
}