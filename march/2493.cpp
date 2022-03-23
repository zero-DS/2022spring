#include <bits/stdc++.h>
using namespace std;
int tower[500001]={100000001};
int receive[500001];
stack<int> s;
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>tower[i];
    }
    s.push(0);
    for(int i=1;i<=N;i++){
        while(1){
            if(tower[i]<tower[s.top()]){
                receive[i]=s.top();
                s.push(i);
                break;
            }
            else{
                s.pop();
            }
        }
    }
    for(int i=1;i<=N;i++)cout<<receive[i]<<' ';
    return 0;
}