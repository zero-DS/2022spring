#include <bits/stdc++.h>
using namespace std;
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    stack<char> paren;
    int ans=0;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(')paren.push('(');
        else{
            if(s[i-1]=='('){
                paren.pop();
                ans+=paren.size();
            }
            else{
                paren.pop();
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}