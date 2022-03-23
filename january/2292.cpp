#include <bits/stdc++.h>
using namespace std;
int main(void){
    int arr[100000]={1,7};
    int N;
    cin>>N;
    for(int i=2;i<100000;i++){
        arr[i]=1+(6+6*(i-1))*(i-1)/2;
        if(N<=arr[i]){
            if(N==1){
                cout<<1;
                break;
            }
            cout<<i;
            break;
        }
    }
    return 0;
}