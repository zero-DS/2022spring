#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    stack< pair<char,int> > paren;
    string s;
    int ans=0,temp;
    cin>>s;
    bool isValid=true;
    for(int i=0;i<s.size();i++){
        if(s[i]=='['){
            paren.push({'[',0});
        }
        else if(s[i]=='('){
            paren.push({'(',0});
        }
        else if(s[i]==']'){
            if(paren.empty()){
                isValid=false;
                break;
            }
            if(paren.top().X=='['){
                if(paren.top().Y==0){
                    paren.pop();
                    if(!paren.empty())paren.top().Y+=3;
                    else ans+=3;
                }
                else{
                    temp=paren.top().Y*3;
                    paren.pop();
                    if(!paren.empty())paren.top().Y+=temp;
                    else ans+=temp;
                }
            }
            else{
                isValid=false;
            }
        }
        else if(s[i]==')'){
            if(paren.empty()){
                isValid=false;
                break;
            }
            if(paren.top().X=='('){
                if(paren.top().Y==0){
                    paren.pop();
                    if(!paren.empty())paren.top().Y+=2;
                    else ans+=2;
                }
                else{
                    temp=paren.top().Y*2;
                    paren.pop();
                    if(!paren.empty())paren.top().Y+=temp;
                    else ans+=temp;
                }
            }
            else{
                isValid=false;
            }
        }
    }
    if(!paren.empty())isValid=false;
    if(!isValid)cout<<0;
    else cout<<ans;
    return 0;
}