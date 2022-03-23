#include <bits/stdc++.h>
using namespace std;
vector< pair<int,int> > v;
int arr[101][100001];
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int N,K;
    cin>>N>>K;
    for(int i=1;i<=N;i++){
        int W,V;
        cin>>W>>V;
        v.push_back({W,V});
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=N;i++){
        for(int j=1;j<=K;j++){
            if(v[i-1].first<=j){
                arr[i][j]=max(arr[i-1][j-v[i-1].first]+v[i-1].second , arr[i-1][j]);
            }
            else{
                arr[i][j]=arr[i-1][j];
            }
        }
    }
    cout<<arr[N][K];
    return 0;
}