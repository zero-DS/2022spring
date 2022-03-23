#include <bits/stdc++.h>
using namespace std;
bool cmp(const tuple<int,int,int,string> &t1, const tuple<int,int,int,string> &t2){
    int a1,b1,c1,a2,b2,c2;
    string s1,s2;
    tie(a1,b1,c1,s1)=t1;
    tie(a2,b2,c2,s2)=t2;
    if(a1==a2){
        if(b1==b2){
            if(c1==c2){
                return s1<s2;
            }
            else return c1>c2;
        }
        else return b1<b2;
    }
    else return a1>a2;
};
vector< tuple<int,int,int,string> > vt;
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        string name;
        int kor,eng,mat;
        cin>>name>>kor>>eng>>mat;
        vt.push_back({kor,eng,mat,name});
    }
    sort(vt.begin(),vt.end(),cmp);
    for(auto s: vt){
        cout<<get<3>(s)<<'\n';
    }
    return 0;
}