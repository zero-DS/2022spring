#include <bits/stdc++.h>
using namespace std;
bool oneHT[100001]={1,1};//1번째 인덱스부터 시작
bool twoHT[100001]={1};
bool threeHT[100001]={1};//값이 0이면 소수
int main(void){
    for(int i=2;i<100000;i++){
        if(oneHT[i]==1)continue;
        for(int j=2;;j++){
            if(i*j>300000)break;
            if(i*j>200000){
                threeHT[i*j-200000]=1;
            }
            else if(i*j>100000){
                twoHT[i*j-100000]=1;
            }
            else{
                oneHT[i*j]=1;
            }
        }
    }
    for(int i=2;i<50000;i++){
        if(twoHT[i]==1)continue;
        for(int j=2;;j++){
            if((i+100000)*j>300000)break;
            if((i+100000)*j>200000){
                threeHT[(i+100000)*j-200000]=1;
            }
            else if((i+100000)*j>100000){
                twoHT[(i+100000)*j-100000]=1;
            }
        }
    }
    while(true){
        int n,cnt=0;
        cin>>n;
        if(n==0)break;
        if(n*2>200000){
            for(int i=1;i<=n*2-200000;i++){
                if(threeHT[i]==0)cnt++;
            }
            for(int i=n+1-100000;i<100001;i++){
                if(twoHT[i]==0)cnt++;
            }
        }
        else if(n*2>100000){
            for(int i=1;i<=n*2-100000;i++){
                if(twoHT[i]==0)cnt++;
            }
            for(int i=n+1;i<100001;i++){
                if(oneHT[i]==0)cnt++;
            }
        }
        else{
            for(int i=n+1;i<=n*2;i++){
                if(oneHT[i]==0)cnt++;
            }
        }
        cout<<cnt<<'\n';
    }

    return 0;
}