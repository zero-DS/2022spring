#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main(void){
    Mat img=imread("/Users/sdsmba/PS/iv/data_src/cat.webp");
    Mat white(200,200,CV_8UC3,Scalar(255,255,255));
    Mat ROI=img(Rect(300,100,white.cols,white.rows));
    
    addWeighted(ROI,0.5,white,0.5,0,ROI);

    imshow("cat",img);

    waitKey(0);
    return 0;
}