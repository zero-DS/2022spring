#include <iostream>
using namespace std;
int main(void){
    int x,y,Quadrant;
    cin>>x;
    cin>>y;
    if(x<0 && y<0)Quadrant=3;
    else if(x<0 && y>0)Quadrant=2;
    else if(x>0 && y<0)Quadrant=4;
    else if(x>0 && y>0)Quadrant=1;
    cout<<Quadrant;

    return 0;
}