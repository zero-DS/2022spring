#include <bits/stdc++.h>
using namespace std;
int N,M;
vector<int> v;
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M;
    int temp;
    for(int i=0;i<N;i++){
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    do{
        for(int i=0;i<M;i++){
            cout<<v[i]<<' ';
        }
        cout<<'\n';
        reverse(v.begin()+M,v.begin()+N);
    }while(next_permutation(v.begin(),v.begin()+N));
    return 0;
}