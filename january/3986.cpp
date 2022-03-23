#include <bits/stdc++.h>
using namespace std;
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int N,ans=0;
    string t;
    cin>>N;
    while(N--){
        stack<char> s;
        cin>>t;
        for(int i=0;i<t.size();i++){
            if(s.size()==0)s.push(t[i]);
            else{
                if(t[i]=='A'){
                    if(s.top()=='B')s.push(t[i]);
                    else s.pop();
                }
                else if(t[i]=='B'){
                    if(s.top()=='A')s.push(t[i]);
                    else s.pop();
                }
            }
        }
        if(s.empty())ans++;
    }
    cout<<ans;
    return 0;
}