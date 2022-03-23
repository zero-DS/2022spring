#include <bits/stdc++.h>
using namespace std;
vector<string> vs;
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        string tmp;
        tmp=s.substr(i);
        vs.push_back(tmp);
    }
    sort(vs.begin(),vs.end());
    for(auto k : vs){
        cout<<k<<'\n';
    }
    return 0;
}