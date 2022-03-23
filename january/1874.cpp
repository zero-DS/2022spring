#include <bits/stdc++.h>
using namespace std;
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    stack<int> s;
    vector<char> ans;
    int N,temp,cnt=1,flag=0;
    cin>>N;
    while(N--){
        cin>>temp;
        while(true){
            if(cnt>temp)break;
            if(cnt==temp){
                s.push(cnt++);
                ans.push_back('+');
                break;
            }
            s.push(cnt++);
            ans.push_back('+');
        }
        if(s.top()==temp){
            s.pop();
            ans.push_back('-');
        }
        else{
            flag=1;
        }
    }
    if(flag)cout<<"NO";
    else for(char c : ans)cout<<c<<'\n';

    return 0;
}