#include <bits/stdc++.h>
using namespace std;
long arr[100000];
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    sort(arr,arr+N);
    int maxoccur=0;
    long long maxstr;
    int curcnt=1;
    for(int i=1;i<N;i++){
        if(arr[i]==arr[i-1])curcnt++;
        else{
            if(maxoccur<curcnt){
                maxoccur=curcnt;
                maxstr=arr[i-1];
            }
            curcnt=1;
        }
    }
    if(maxoccur<curcnt){//마지막 원소가 가장 많이 갖고있는 카드인경우
        maxoccur=curcnt;
        maxstr=arr[N-1];
    }
    cout<<maxstr;
    return 0;
}