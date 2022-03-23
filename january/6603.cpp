#include <bits/stdc++.h>
using namespace std;
int arr[12];
int seq[12];
bool visited[12];
int cmd;
void lotto(int n){
    if(n==6){
        for(int i=1;i<6;i++){
            if(seq[i]<seq[i-1])return;
        }
        for(int i=0;i<6;i++){
            cout<<seq[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=0;i<cmd;i++){
        if(visited[i]==false){
            visited[i]=true;
            seq[n]=arr[i];
            lotto(n+1);
            visited[i]=false;
        }
    }
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    cin>>cmd;
    while(cmd){
        for(int i=0;i<cmd;i++){
            cin>>arr[i];
        }
        lotto(0);
        cout<<'\n';
        cin.get();
        cin>>cmd;
    }
    return 0;
}