#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main(void){
    int data1[10]={500,100,-500,1000,0,500,100,-500,2000,0};
    float data2[9]={0.1f,5.1f,-0.2f,0.1f,4.1f,-0.3f,0.1f,3.1f,-0.4f};

    Mat m1(2,5,CV_32S,data1);
    Mat m2(3,3,CV_32F,data2);

    cout<<"m1 : \n"<<m1<<'\n';
    cout<<"m2 : \n"<<m2<<'\n';

    Mat m3 = Mat_<float>({3,2},{1,1,2,2,3,3});
    Mat m4 = Mat_<float>({2,3},{0.1f,5.1f,-0.2f,0.1f,4.1f,-0.3f});
    cout<<"m3 : \n"<<m3<<'\n';
    cout<<"m4 : \n"<<m4<<'\n';

    Mat m11(2,2,CV_8UC3);
    Mat m22(2,2,CV_8UC3);
    Mat m33(2,2,CV_8UC3);
    Mat m44(2,2,CV_8UC3);
    Mat m55(2,2,CV_8UC3);
    Mat m66(2,2,CV_8UC3);

    m11=255;
    m22=Scalar(255,0,0);
    m33=Scalar(255,255,255);
    m44.setTo(255);
    m55.setTo(Scalar(255,0,0));
    m66.setTo(Scalar(255,255,255));

    cout<<endl<<m11<<endl;
    cout<<m22<<endl;
    cout<<m33<<endl;
    cout<<m44<<endl;
    cout<<m55<<endl;
    cout<<m66<<endl<<endl;

    Mat m(10,15,CV_16S);
    m.setTo(100);
    Mat two=m(Rect(3,1,5,4));
    two.setTo(200);
    Mat three=m(Rect(8,5,6,4));
    three.setTo(300);
    Mat five=m(Rect(5,3,5,4));
    five.setTo(500);
    cout<<m;
    return 0;
}