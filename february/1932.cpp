#include <bits/stdc++.h>
using namespace std;
int tri[502][502];
int arr[502][502];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<i+1;j++){
            cin>>tri[i][j];
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<i+1;j++){
            if(i==1){
                arr[i][j]=tri[i][j];
            }
            else{
                arr[i][j]=max(arr[i-1][j-1],arr[i-1][j])+tri[i][j];
            }
        }
    }
    int ans=0;
    for(int i=1;i<n+1;i++)ans=max(ans,arr[n][i]);
    cout<<ans;
    return 0;
}