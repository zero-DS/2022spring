#include <bits/stdc++.h>
using namespace std;
bool visited[8];
int seq[8];
int arr[8];
int N,M;
void NM(int n){
    if(n==M){
        for(int i=1;i<M;i++){
            if(seq[i]<seq[i-1])return;
        }
        for(int i=0;i<M;i++){
            cout<<seq[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    int temp=0;
    for(int i=0;i<N;i++){
        if(visited[i]==false && temp!=arr[i]){
            visited[i]=true;
            seq[n]=arr[i];
            temp=seq[n];
            NM(n+1);
            visited[i]=false;
        }
    }
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    sort(arr,arr+N);
    NM(0);
    return 0;
}