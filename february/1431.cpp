#include <bits/stdc++.h>
using namespace std;
bool cmp(const string &a, const string &b){
    if(a.length()<b.length()) return true;
    else if(a.length()>b.length()) return false;
    else{
        int asum=0,bsum=0;
        for(int i=0;i<a.length();i++){
            if(a[i]>='0' && a[i]<='9')asum+=a[i]-'0';
            if(b[i]>='0' && b[i]<='9')bsum+=b[i]-'0';
        }
        if(asum<bsum) return true;
        else if(asum>bsum) return false;
        else{
            if(a.compare(b)<0)return true;
            else return false;
        }
    }
}
string arr[50];
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    sort(arr,arr+N,cmp);
    for(int i=0;i<N;i++){
        cout<<arr[i]<<'\n';
    }
    return 0;
}