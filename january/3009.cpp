#include <bits/stdc++.h>
using namespace std;
int main(void){
    int arrX[4]={};
    int arrY[4]={};
    for(int i=0;i<3;i++){
        cin>>arrX[i]>>arrY[i];
    }
    if(arrX[0]==arrX[1])arrX[3]=arrX[2];
    else if(arrX[0]==arrX[2])arrX[3]=arrX[1];
    else if(arrX[1]==arrX[2])arrX[3]=arrX[0];
    if(arrY[0]==arrY[1])arrY[3]=arrY[2];
    else if(arrY[0]==arrY[2])arrY[3]=arrY[1];
    else if(arrY[1]==arrY[2])arrY[3]=arrY[0];
    cout<<arrX[3]<<' '<<arrY[3];
    return 0;
}