#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    int arr[8001]={0};
    int N,temp;
    cin>>N;
    double sum=0;
    for(int i=0;i<N;i++){
        cin>>temp;
        arr[temp+4000]++;
        sum+=temp;
    }
    double avg=sum/N;
    printf("%.lf\n",floor(avg+0.5));
    int cnt=0;
    for(int i=0;i<8001;i++){
        cnt+=arr[i];
        if(cnt>N/2){
            printf("%d\n",i-4000);
            break;
        }
    }
    int max=1,maxI=9999,maxI2=9999;
    for(int i=8000;i>=0;i--){
        if(max<arr[i]){
            max=arr[i];
            maxI=i-4000;
            maxI2=9999;
        }
        else if(max==arr[i]){
            if(maxI>i-4000){
                maxI2=maxI;
                maxI=i-4000;
            }
        }
    }
    if(maxI2==9999)printf("%d\n",maxI);
    else printf("%d\n",maxI2);
    
    int minNum=9999,maxNum=-9999;
    for(int i=0;i<8001;i++){
        if(arr[i]!=0 && minNum==9999){
            minNum=i-4000;
            break;
        }
    }
    for(int i=8001-1;i>=0;i--){
        if(arr[i]!=0 && maxNum==-9999){
            maxNum=i-4000;
            break;
        }
    }
    printf("%d",maxNum-minNum);
    return 0;
}