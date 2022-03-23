#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int N,M,temp;
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.begin()+N);
    do{
        bool flag=true;
        for(int i=1;i<M;i++){
            if(v[i]<v[i-1])flag=false;
        }
        if(!flag)continue;
        for(int i=0;i<M;i++){
            cout<<v[i]<<' ';
        }
        cout<<'\n';
        reverse(v.begin()+M,v.begin()+N);
    }while(next_permutation(v.begin(),v.begin()+N));
    return 0;
}