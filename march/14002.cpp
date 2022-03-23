#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int slen[1001];
int pre[1001];
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
        slen[i]=1;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<i;j++){
            if(arr[j]<arr[i] && slen[j]>=slen[i]){
                slen[i]=slen[j]+1;
                pre[i]=j;
            }
        }
    }
    int maxidx=0;
    for(int i=1;i<=N;i++){
        if(slen[maxidx]<slen[i])maxidx=i;
    }
    cout<<slen[maxidx]<<'\n';
    int track=maxidx;
    stack<int> s;
    for(int i=0;i<slen[maxidx];i++){
        s.push(arr[track]);
        track=pre[track];
    }
    while(!s.empty()){
        cout<<s.top()<<' ';
        s.pop();
    }
    return 0;
}