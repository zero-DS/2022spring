#include <bits/stdc++.h>
using namespace std;
int arr[1000000];
int sorted[1000000];
void mergeNsort(int left, int mid, int right){
    int i=left,j=mid+1;
    int s=left;
    while(true){
        if(i>mid || j>right)break;
        if(arr[i]<arr[j])sorted[s++]=arr[i++];
        else sorted[s++]=arr[j++];
    }
    if(i>mid){
        for(int k=j;k<right+1;k++){
            sorted[s++]=arr[k];
        }
    }
    else{
        for(int k=i;k<mid+1;k++){
            sorted[s++]=arr[k];
        }
    }
    for(int k=left;k<right+1;k++){
        arr[k]=sorted[k];
    }
};
void divide(int left, int right){
    if(left<right){
        int mid=(left+right)/2;
        divide(left,mid);
        divide(mid+1,right);
        mergeNsort(left,mid,right);
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    divide(0,N-1);
    for(int i=0;i<N;i++){
        cout<<arr[i]<<'\n';
    }
    return 0;
}