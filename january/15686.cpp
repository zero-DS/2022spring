#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int board[50][50];
bool chicused[13];
vector< pair<int,int> > chic;
vector< pair<int,int> > house;
int N,M,minans=99999;
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>board[i][j];
            if(board[i][j]==1)house.push_back({i,j});
            else if(board[i][j]==2)chic.push_back({i,j});
        }
    }
    fill(chicused,chicused+chic.size(),1);
    for(int i=0;i<chic.size()-M;i++)chicused[i]=0;
    do{
        int sum=0;
        for(int i=0;i<house.size();i++){
            int mindist=99999;
            for(int j=0;j<chic.size();j++){
                if(chicused[j])mindist=min(mindist,abs(house[i].X-chic[j].X)+abs(house[i].Y-chic[j].Y));
            }
            sum+=mindist;
        }
        minans=min(minans,sum);//sum은 도시의 치킨거리
    }while(next_permutation(chicused,chicused+chic.size()));
    cout<<minans;
    return 0;
}