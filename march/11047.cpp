#include <bits/stdc++.h>
using namespace std;
int arr[11];
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int N,K;
    cin>>N>>K;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }
    int coins=0;
    int idx=N;
    while(idx>0){
        if(K>=arr[idx]){
            K-=arr[idx];
            coins++;
        }
        else idx--;
    }
    cout<<coins;
    return 0;
}