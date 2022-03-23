#include <bits/stdc++.h>
using namespace std;
int dn(int a);
int main(void){
    int arr[10001]={0};
    for(int i=1;i<=10000;i++){
        int index=dn(i);
        if(index<=10000)arr[index]=1;
    }
    for(int i=1;i<=10000;i++){
        if(arr[i]==0)printf("%d\n",i);
    }

    return 0;
}
int dn(int a){
    int sum=a;
    while(a>0){
        sum+=(a%10);
        a/=10;
    }
    return sum;
}