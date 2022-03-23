#include <bits/stdc++.h>
using namespace std;
int arr[1000001];
int path[1000001];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin>>N;
    arr[1]=0;
    for(int i=2;i<N+1;i++){
        arr[i]=arr[i-1]+1;
        path[i]=i-1;
        if(i%2==0 && arr[i]>arr[i/2]){
            arr[i]=arr[i/2]+1;
            path[i]=i/2;
        }
        if(i%3==0 && arr[i]>arr[i/3]){
            arr[i]=arr[i/3]+1;
            path[i]=i/3;
        }
    }
    cout<<arr[N]<<'\n';
    int idx=N;
    while(1){
        cout<<idx<<' ';
        if(idx==1)break;
        idx=path[idx];
    }
    return 0;
}