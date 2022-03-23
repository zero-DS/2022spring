#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main(void){
    Mat A(100,200,CV_8UC3,Scalar(255,255,255));
    Rect R(90,40,20,20);
    Rect R1,R2,R3;
    Point P(50,0);

    rectangle(A,R-P,Scalar(0,0,255));
    rectangle(A,R,Scalar(255,0,0));
    rectangle(A,R+P,Scalar(0,255,0));

    imshow("test",A);
    waitKey(0);
    return 0;
}