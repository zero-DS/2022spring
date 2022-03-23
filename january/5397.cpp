#include <bits/stdc++.h>
using namespace std;
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    string s;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        list<char> List;
        list<char>::iterator iter=List.end();
        cin>>s;
        for(int j=0;j<s.size();j++){
            if(s[j]=='<'){
                if(iter!=List.begin())iter--;
            }
            else if(s[j]=='>'){
                if(iter!=List.end())iter++;
            }
            else if(s[j]=='-'){
                if(iter!=List.begin())iter=List.erase(--iter);
            }
            else{
                List.insert(iter,s[j]);
            }
        }
        for(auto k : List)cout<<k;
        cout<<'\n';
    }
    return 0;
}