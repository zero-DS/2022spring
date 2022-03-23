#include <bits/stdc++.h>
using namespace std;
void sequence(int n);
int N, M;
bool visited[9]={0};
int num[9]={0};
int main(void){
    cin>>N>>M;
    sequence(0);
    return 0;
}
void sequence(int n){
    if(n==M){
        for(int i=1;i<=M;i++){
            cout<<num[i]<<' ';
        }
        cout<<'\n';
    }
    else{
        for(int i=1;i<=N;i++){
            if(visited[i]==false){
                visited[i]=true;
                num[n+1]=i;
                sequence(n+1);
                visited[i]=false;
            }
        }
    }
}
