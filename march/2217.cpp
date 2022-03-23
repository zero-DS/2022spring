#include <bits/stdc++.h>
using namespace std;
deque<int> d;
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        d.push_back(num);
    }
    sort(d.begin(),d.end());
    int ans=0;
    for(int i=N-1;i>=0;i--){
        ans=max(ans,d[i]*(N-i));
    }
    cout<<ans;
    return 0;
}