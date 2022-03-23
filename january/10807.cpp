#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,v,cnt=0;
    int arr[100]={0};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>v;
    for(int i=0;i<n;i++){
        if(arr[i]==v)cnt++;
    }
    cout<<cnt;

    return 0;
}