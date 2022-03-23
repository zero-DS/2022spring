#include <bits/stdc++.h>
using namespace std;
int arr[1000001]={-1,0,1,1};
void dp(int cur){
    if(cur%3==0 && cur%2==0)arr[cur]=min(min(arr[cur/3],arr[cur/2]),arr[cur-1])+1;
    else if(cur%3==0)arr[cur]=min(arr[cur/3],arr[cur-1])+1;
    else if(cur%2==0)arr[cur]=min(arr[cur/2],arr[cur-1])+1;
    else arr[cur]=arr[cur-1]+1;
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    for(int i=4;i<1000001;i++){
        dp(i);
    }
    int N;
    cin>>N;
    cout<<arr[N];
    return 0;
}