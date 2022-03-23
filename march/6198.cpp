#include <bits/stdc++.h>
using namespace std;
stack<int> s;
long long ans=0;
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        long long tmp;
        cin>>tmp;
        if(!s.empty()){
            while(s.top()<=tmp){
                s.pop();
                if(s.empty())break;
            }
        }
        s.push(tmp);
        ans+=s.size()-1;
    }
    cout<<ans;
    return 0;
}