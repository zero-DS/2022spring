#include <bits/stdc++.h>
using namespace std;
vector< deque<bool> > tobnis;
int K,target,dir;
void turn(int t, int d, int from){//from은 어느 방향에서 영향을 받아 톱니를 돌렸는가
    bool temp;
    bool Requal=true;
    bool Lequal=true;
    if(from!=1 && t!=3 && tobnis[t][2]!=tobnis[t+1][6])Requal=false;//1,4번 톱니는 더이상 진행하지 않는다
    if(from!=-1 && t!=0 && tobnis[t][6]!=tobnis[t-1][2])Lequal=false;// 왼쪽에서 영향을 받아 돌리게 된 톱니는 왼쪽 톱니에 다시 영향 안줌
    if(d==1){//시계
        temp=tobnis[t].back();
        tobnis[t].pop_back();
        tobnis[t].push_front(temp);
    }
    else if(d==-1){//반시계
        temp=tobnis[t].front();
        tobnis[t].pop_front();
        tobnis[t].push_back(temp);
    }
    if(!Requal)turn(t+1,d*(-1),-1);
    if(!Lequal)turn(t-1,d*(-1),1);
};
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    for(int i=0;i<4;i++){
        deque<bool> temp;
        for(int j=0;j<8;j++){
            int bt=cin.get()-'0';
            temp.push_back(bt);
        }
        cin.get();
        tobnis.push_back(temp);
    }
    cin>>K;
    while(K--){
        cin>>target>>dir;
        turn(target-1,dir,0);
    }
    int ans=0;
    if(tobnis[0].front())ans+=1;
    if(tobnis[1].front())ans+=2;
    if(tobnis[2].front())ans+=4;
    if(tobnis[3].front())ans+=8;
    cout<<ans;
    return 0;
}