#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n,w,L;
int curweight=0,ans=0;
queue<int> Q;
deque< pair<int,int> > bridge;
bool pass(){
    if(bridge.empty() && Q.empty())return 0;
    if(!Q.empty() && curweight+Q.front()<=L){//다리에 아직 남아있고 큐가 텅 비어있을수 있으므로 조건 저렇게 함
        bridge.push_back({Q.front(),0});
        curweight+=Q.front();
        Q.pop();
    }
    //for(auto k : bridge)k.Y++; //이거 왜 안되지
    for(int i=0;i<bridge.size();i++){
        bridge[i].Y++;
    }
    if(bridge.front().Y==w){
        curweight-=bridge.front().X;
        bridge.pop_front();
    }
    return 1;
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>w>>L;
    while(n--){
        int temp;
        cin>>temp;
        Q.push(temp);
    }
    while(pass()){
        ans++;
    }
    cout<<ans+1;
    return 0;
}