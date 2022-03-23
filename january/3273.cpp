#include <bits/stdc++.h>
using namespace std;
int x;
int* arr;
bool num[2000001]={0};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int n,cnt=0;
    cin>>n;
    arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>x;
    for(int i=0;i<n;i++){
        if(x-arr[i]>0 && num[x-arr[i]])cnt++;
        num[arr[i]]=1;
    }
    cout<<cnt;
    delete[] arr;
    return 0;
}