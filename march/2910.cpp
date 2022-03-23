#include <bits/stdc++.h>
using namespace std;
vector< tuple<int,int,int> > v;
bool cmp(tuple<int,int,int> t1, tuple<int,int,int> t2){
    int X1,Y1,Z1;
    int X2,Y2,Z2;
    tie(X1,Y1,Z1)=t1;
    tie(X2,Y2,Z2)=t2;
    if(X1>X2){
        return true;
    }
    if(X1==X2){
        if(Y1<Y2)return true;
    }
    return false;
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int N,C;
    cin>>N>>C;
    int var=0;
    for(int i=0;i<N;i++){
        bool flag=0;
        int tmp;
        cin>>tmp;
        int X,Y,Z;
        for(int j=0;j<var;j++){
            tie(X,Y,Z)=v[j];
            if(Z==tmp){
                v[j]={X+1,Y,Z};
                flag=true;
            }
        }
        if(flag==false){
            v.push_back({1,var,tmp});
            var++;
        }
    }
    sort(v.begin(),v.end(),cmp);
    int X,Y,Z;
    for(int i=0;i<var;i++){
        tie(X,Y,Z)=v[i];
        for(int j=0;j<X;j++){
            cout<<Z<<' ';
        }
    }
    return 0;
}