#include <bits/stdc++.h>
using namespace std;
bool visited[7];
int arr[7]; 
int N,M;
void NM(int n){
    if(n==M){
        for(int i=0;i<M;i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=1;i<=N;i++){
        arr[n]=i;
        NM(n+1);
        arr[n]=0;
    }
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M;
    NM(0);
    return 0;

}
