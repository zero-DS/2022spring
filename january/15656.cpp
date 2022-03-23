#include<bits/stdc++.h>
using namespace std;
bool visited[10000];
int arr[7];
int seq[7];
int N,M;
void NM(int n){
    if(n==M){
        for(int i=0;i<M;i++){
            cout<<seq[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=0;i<N;i++){
        visited[arr[i]]=true;
        seq[n]=arr[i];
        NM(n+1);
        visited[arr[i]]=false;
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