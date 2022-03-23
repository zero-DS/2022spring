#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector< pair<int,int> > v;
bool cmp(const pair<int,int> &p1, const pair<int,int> &p2){
    if(p1.second>p2.second)return true;
    else return false;
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N,C;
    cin>>N>>C;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        bool flag=0;
        for(auto &a : v){
            if(tmp==a.X){
                a.Y++;
                flag=1;
                break;
            }
        }
        if(!flag)v.push_back({tmp,1});
    }
    stable_sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].Y;j++)cout<<v[i].X<<' ';
    }
    return 0;
}