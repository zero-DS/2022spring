#include <bits/stdc++.h>
using namespace std;
int N,M;
vector<int> v={1,2,3,4,5,6,7,8};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M;
    do{
        bool flag=0;
        for(int i=1;i<M;i++){
            if(v[i]<v[i-1])flag=1;
        }
        if(flag)continue;
        for(int i=0;i<M;i++){
            cout<<v[i]<<' ';
        }
        cout<<'\n';
        reverse(v.begin()+M,v.begin()+N);
    }while(next_permutation(v.begin(),v.begin()+N));
    return 0;
}