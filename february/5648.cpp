#include <bits/stdc++.h>
using namespace std;
long long arr[1000000];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    string tmp;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp;
        long long ten=1;
        long long sum=0;
        for(int j=0;j<tmp.length();j++){
            sum+=(tmp[j]-'0')*ten;
            ten*=10;
        }
        arr[i]=sum;
    }
    sort(arr,arr+N);
    for(int i=0;i<N;i++){
        cout<<arr[i]<<'\n';
    }
    return 0;
}