#include <bits/stdc++.h>
using namespace std;
deque<int> vip;
int arr[41]={1,1,2};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int N,M;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int tmp;
        cin>>tmp;
        vip.push_back(tmp);
    }
    for(int i=3;i<=40;i++)arr[i]=arr[i-1]+arr[i-2];
    int ans=1,cur=0;
    if(M>0){
        for(int i=0;i<M;i++){
            ans*=arr[vip[i]-cur-1];
            cur=vip[i];
        }
        ans*=arr[N-vip[M-1]];
    }
    else ans=arr[N];
    cout<<ans;
    return 0;
}