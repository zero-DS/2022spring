#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main(void){
    Mat image(300,500,CV_8UC1,Scalar(255));

    Size2f size(200,20);
    Point2f P(250,150);
    
    Rect R(Point(245,145),Size(10,10));
    rectangle(image,R,Scalar(0,255,0));// 얘는 포인트가 왼쪽 위 꼭지점

    RotatedRect R1(P,size,0.f); //얘는 포인트가 가운데 지점
    RotatedRect R2(P,size,45.f);
    RotatedRect R3(P,size,90.f);
    RotatedRect R4(P,size,135.f);
    Point2f pts1[4];
    Point2f pts2[4];
    Point2f pts3[4];
    Point2f pts4[4];
    R1.points(pts1);
    R2.points(pts2);
    R3.points(pts3);
    R4.points(pts4);
    for(int i=0;i<4;i++){
        line(image,pts1[i],pts1[(i+1)%4],Scalar(0,0,0));
        line(image,pts2[i],pts2[(i+1)%4],Scalar(0,0,0));
        line(image,pts3[i],pts3[(i+1)%4],Scalar(0,0,0));
        line(image,pts4[i],pts4[(i+1)%4],Scalar(0,0,0));
    }
    
    imshow("test",image);
    waitKey(0);
    return 0;
}