#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N;
    cin>>N;
    int** arr=new int*[3];//0칸에는 키, 1칸에는 몸무게, 2칸에는 등수
    for(int i=0;i<3;i++){
        arr[i]=new int[N];
    }
    for(int i=0;i<N;i++){
        cin>>arr[0][i]>>arr[1][i];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j)continue;
            if(arr[0][i]<arr[0][j] && arr[1][i]<arr[1][j])arr[2][i]++;
        }
    }
    for(int i=0;i<N;i++){
        cout<<arr[2][i]+1<<' ';
    }
    for(int i=0;i<3;i++){
        delete[]arr[i];
    }
    delete[] arr;
    return 0;
}