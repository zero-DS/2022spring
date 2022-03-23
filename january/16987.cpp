#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector< pair<int,int> > eggs;
int N,armor,weight,maxcnt=0,cnt=0;
void hitegg(int hold){
    if(hold==N){
        maxcnt=max(maxcnt,cnt);
        return;
    }
    if(eggs[hold].X<=0 || cnt==N-1){
        hitegg(hold+1);
        return;
    }
    for(int i=0;i<N;i++){
        if(eggs[i].X>0 && i!=hold){
            eggs[hold].X-=eggs[i].Y;
            eggs[i].X-=eggs[hold].Y;
            if(eggs[hold].X<=0)cnt++;
            if(eggs[i].X<=0)cnt++;
            hitegg(hold+1);
            if(eggs[hold].X<=0)cnt--;
            if(eggs[i].X<=0)cnt--;
            eggs[hold].X+=eggs[i].Y;
            eggs[i].X+=eggs[hold].Y;
        }
    }
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>armor>>weight;
        eggs.push_back({armor,weight});
    }
    hitegg(0);
    cout<<maxcnt;
    return 0;
}