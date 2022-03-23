#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    vector<int> v;
    int N,temp;
    double sum=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>temp;
        v.push_back(temp);
        sum+=temp;
    }
    sort(v.begin(),v.end());
    cout<<round(sum/N)<<'\n';
    cout<<v[N/2]<<'\n';
    int cnt=1,cntMax=1,num1=9999,num2=9999;
    for(int i=1;i<N;i++){
        if(v[i]==v[i-1]){
            cnt++;
            if(cnt==cntMax){
                if(num1==9999)num1=v[i];
                else if(num2==9999)num2=v[i];
            }
            if(cnt>cntMax){
                cntMax=cnt;
                num1=v[i];
                num2=9999;
            }
        }
        else{
            cnt=1;
            if(num1==9999)num1=v[i];
        }
    }
    if(N==1)cout<<v[0]<<'\n';
    else{
        if(num2==9999)cout<<num1<<'\n';
        else cout<<num2<<'\n';
    }
    cout<<v[N-1]-v[0]<<'\n';
    return 0;
}