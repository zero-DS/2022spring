#include <bits/stdc++.h>
using namespace std;
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    list<int> yose;
    int N,K;
    cin>>N>>K;
    for(int i=1;i<=N;i++)yose.push_back(i);
    list<int>::iterator iter=yose.begin();
    cout<<'<';
    for(int i=0;i<N;i++){
        int cnt=K-1;
        while(cnt--){
            iter++;
            if(iter==yose.end())iter=yose.begin();
        }
        int temp=*iter;
        iter=yose.erase(iter);
        if(iter==yose.end())iter=yose.begin();
        if(i==N-1)cout<<temp<<'>';
        else cout<<temp<<", ";
    }

    return 0;
}