#include <bits/stdc++.h>
using namespace std;
int T,N,M;
vector<int> A;
vector<int> B;
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    cin>>T;
    while(T--){
        cin>>N>>M;
        for(int i=0;i<N;i++){
            int tmp;
            cin>>tmp;
            A.push_back(tmp);
        }
        for(int i=0;i<M;i++){
            int tmp;
            cin>>tmp;
            B.push_back(tmp);
        }
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        long long cnt=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(A[i]<=B[j])break;
                else cnt++;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}