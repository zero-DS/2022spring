#include <bits/stdc++.h>
using namespace std;
deque<int> q;
int getIdx(int t){
    for(int i=0;i<q.size();i++){
        if(q[i]==t)return i;
    }
    return -1;
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int N,M;
    int ans=0;
    cin>>N>>M;
    for(int i=1;i<=N;i++)q.push_back(i);
    for(int i=0;i<M;i++){
        int tmp;
        cin>>tmp;
        int idx=getIdx(tmp);
        if(idx==0){
            q.pop_front();
            continue;
        }
        if(q.size()/2>=idx){
            for(int j=0;j<idx;j++){
                int popped=q.front();
                q.pop_front();
                q.push_back(popped);
                ans++;
            }
        }
        else{
            for(int j=idx;j<q.size();j++){
                int popped=q.back();
                q.pop_back();
                q.push_front(popped);
                ans++;
            }
        }
        q.pop_front();
    }
    cout<<ans;
    return 0;
}