#include <bits/stdc++.h>
using namespace std;
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--){
        deque<int> dq;
        string p,t;
        int errorFlag=0;
        int reverseFlag=0;
        char temp;
        cin>>p;
        int n;
        cin>>n;
        temp=cin.get();
        while(true){
            temp=cin.get();
            if(temp=='[')continue;
            if(temp==',' || temp==']'){
                int sum=0;
                for(int i=0;i<t.size();i++){
                    sum+=(int)pow(10,i)*(t[t.size()-i-1]-'0');
                }
                if(sum!=0)dq.push_back(sum);
                t.clear();
                if(temp==']')break;
            }
            else t+=temp;
        }
        for(int i=0;i<p.size();i++){
            if(p[i]=='R'){
                reverseFlag=1-reverseFlag;
            }
            else if(p[i]=='D'){
                if(!dq.size() || n==0){
                    errorFlag=1;
                    break;
                }
                if(reverseFlag)dq.pop_back();
                else dq.pop_front();
            }
        }
        if(errorFlag){
            cout<<"error\n";
            continue;
        }
        if(reverseFlag)reverse(dq.begin(),dq.end());
        if(dq.size()==0)cout<<"[]\n";
        else cout<<'[';
        for(int i=0;i<dq.size();i++){
            cout<<dq[i];
            if(i==dq.size()-1)cout<<']'<<'\n';
            else cout<<',';
        }
    }
    return 0;
}