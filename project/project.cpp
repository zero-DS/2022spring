#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <istream>
#include <opencv2/opencv.hpp>
#define CVUI_IMPLEMENTATION
#include "cvui.h"
using namespace std;
using namespace cv;
using namespace cv::dnn;

// Constants.
const float INPUT_WIDTH = 640.0;
const float INPUT_HEIGHT = 640.0;
const float SCORE_THRESHOLD = 0.5;
const float NMS_THRESHOLD = 0.45;
const float CONFIDENCE_THRESHOLD = 0.45;
// Text parameters.
const float FONT_SCALE = 0.5;
const int FONT_FACE = FONT_HERSHEY_SIMPLEX;
const float THICKNESS = 0.5;
// Colors.
Scalar BLACK = Scalar(0,0,0);
Scalar BLUE = Scalar(255, 178, 50);
Scalar YELLOW = Scalar(0, 255, 255);
Scalar RED = Scalar(0,0,255);

vector<int> DLlist; // detected labels index list
void draw_label(Mat&, string, int, int);
vector<Mat> pre_process(Mat&, Net&);
Mat post_process(Mat&, vector<Mat>&, const vector<string>&);
vector<string> csv_read_row(istream&, char); //csv reader
int getClickedCocktail(int, Point);
void blendImage(Mat, Mat);
int main(void){
    // Load class list.
    vector<string> class_list;
    ifstream ifs("/Users/sdsmba/PS/project/names.txt");
    string line;
    while(getline(ifs, line)){
        class_list.push_back(line);
    }

    while(1){
        //clear vector
        DLlist.clear();
        vector<int>().swap(DLlist);
        //Show main window
        Mat main_window(720,1080,CV_8UC3,Scalar(130,216,150));
        cvui::rect(main_window,430,5,230,35,0x000000);
        putText(main_window,"Cocktail Vision",Point(430,33),FONT_FACE,1.0,Scalar(255,0,0),2,LINE_AA);
        cvui::text(main_window,10,50,"If you take a picture of your liquors,",0.7,0x000000);
        cvui::text(main_window,10,80,"This program tells you what kinds of cocktails you can make, and how to make them.",0.7,0x000000);
        cvui::text(main_window,10,110,"To take a picture, please take the camera towards to bottles, and press enter.",0.7,0x000000);
        cvui::text(main_window,840,690,"Press ESC to exit",0.7,0x444444);

        imshow("main window", main_window);
        cvui::init("main window");

        // Load image.
        VideoCapture cap(0);
        cap.set(CAP_PROP_FRAME_WIDTH, 640);
        cap.set(CAP_PROP_FRAME_HEIGHT, 640);
        if (!cap.isOpened()){
            printf("Can't open the camera");
            return -1;
        }
        Mat webcamimg, frame;
        while(1){
            cap >> webcamimg;
            cvui::image(main_window,400,200,webcamimg);
            imshow("main window",main_window);
            char key = waitKey(1);
            if (key == 13){
                cap >> frame;
                break;
            }
            else if(key == 27){
                exit(1);
            }
        }
        //copy captured webcam image
        Mat fclone = frame.clone(); 

        // Load model.
        Net net = readNet("/Users/sdsmba/PS/project/exp/weights/best.onnx");
        if(net.empty()){
            cerr<<"Network load failed!\n";
            return -1;
        }

        vector<Mat> detections = pre_process(frame, net);
        Mat img = post_process(fclone, detections, class_list);

        // Put efficiency information.
        // The function getPerfProfile returns the overall time for    
        // inference(t) and the timings for each of the layers(in layersTimes).
        vector<double> layersTimes;
        double freq = getTickFrequency() / 1000;
        double t = net.getPerfProfile(layersTimes) / freq;
        string label = format("Inference time : %.2f ms", t);
        putText(img, label, Point(15, 15), FONT_FACE, FONT_SCALE, RED);

        vector<string> possible_cocktail_name_list;
        vector<string> possible_cocktail_glass_list;
        vector<string> possible_cocktail_method_list;
        vector<string> possible_cocktail_garnish_list;
        vector<string> possible_cocktail_ingredients_list;
        int row_read_cnt = 0;
        ifstream file("/Users/sdsmba/PS/project/cocktaildata.csv");
        if(file.fail())cout<<"error";
        while(file.good()){
            bool isPossible = true;
            vector<string> row = csv_read_row(file, ',');
            row_read_cnt++;
            if(row_read_cnt == 1)continue; //skip first row(column names)
            for(int i=1;i<11;i++){
                if(!isPossible) break;//escape if current cocktail is not makeable
                int ingredient_value = stoi(row[i]);
                if(ingredient_value > 0){ //check if this ingredient exists in DLlist
                    bool ingredientFlag = false;
                    for(int j=0;j<DLlist.size();j++){
                        if(i==DLlist[j]+1){
                            ingredientFlag = true;
                            break;
                        }
                    }
                    if(!ingredientFlag) isPossible = false; //if DLlist does not contain ingredient, this cocktail is impossible
                }
            }
            if(isPossible){//if possible, store names, glasses, methods, garnishes, ingredient lists
                possible_cocktail_name_list.push_back(row[0]);
                possible_cocktail_glass_list.push_back(row[11]);
                possible_cocktail_method_list.push_back(row[12]);
                possible_cocktail_garnish_list.push_back(row[13]);
                possible_cocktail_ingredients_list.push_back(row[14]);
            }
        }
        file.close();

        //after detection
        Mat description_window(Size(720,480), CV_8UC3);
        cvui::image(main_window,400,200,img);
        cvui::text(main_window,20,150,"Possible Cocktail List",1.0,0x0000FF);
        int ypos = 175;
        for(auto c : possible_cocktail_name_list){//make button for each possible cocktails
            ypos += 25;
            cvui::rect(main_window,10,ypos,350,24,0x000000,0xCCCCCC);
            cvui::text(main_window,10,ypos,c,0.6,0x000000);
        }
        cvui::rect(main_window,650,150,150,35,0xff0000,0xff0000);
        cvui::text(main_window,650,153,"Redetect",1.0,0x000000);

        //make description window if cocktail was clicked
        while(1){
            imshow("main window",main_window);
            waitKey(0);
            int clickedCocktail = getClickedCocktail(possible_cocktail_name_list.size(),cvui::mouse("main window")); //get which button is clicked
            cout<<"cc : "<<clickedCocktail<<endl;
            if(clickedCocktail >= 0){
                description_window = Scalar(130,216,150);
                cv::line(description_window,Point(10,220),Point(710,220),Scalar(0,0,0),3.0,LINE_8);
                cvui::text(description_window,550,450,"Press ESC to exit",0.5,0x444444);

                int circlePos = 258;
                for(int i=0;i<5;i++){
                    circle(description_window,Point(20,circlePos),5,Scalar(0,0,0),-1,LINE_AA);
                    circlePos +=30;
                }
                cvui::text(description_window,35,250,"Name",0.6,0x000000);
                cvui::text(description_window,35,280,"Glass",0.6,0x000000);
                cvui::text(description_window,35,310,"Method",0.6,0x000000);
                cvui::text(description_window,35,340,"Garnish",0.6,0x000000);
                cvui::text(description_window,35,370,"Ingredients",0.4,0x000000);
                int colonPos = 253;
                for(int i=0;i<5;i++){
                    cvui::text(description_window,113,colonPos,":",0.4,0x000000);
                    colonPos += 30;
                }
                cvui::text(description_window,125,250,possible_cocktail_name_list[clickedCocktail],0.6,0x000000);
                cvui::text(description_window,125,280,possible_cocktail_glass_list[clickedCocktail],0.6,0x000000);
                cvui::text(description_window,125,310,possible_cocktail_method_list[clickedCocktail],0.6,0x000000);
                cvui::text(description_window,125,340,possible_cocktail_garnish_list[clickedCocktail],0.6,0x000000);
                cvui::text(description_window,125,370,possible_cocktail_ingredients_list[clickedCocktail],0.4,0x000000);
                string imgPath = "/Users/sdsmba/PS/project/images/" + possible_cocktail_name_list[clickedCocktail] + ".png";
                cout<<imgPath<<endl;
                Mat cocktailImg = imread(imgPath,IMREAD_UNCHANGED);
                Mat cocktailBackground(Size(200,200),CV_8UC3,Scalar(130,216,150));
                if(cocktailImg.empty()){
                    cerr<<"Image Load Failed!\n";
                    return -1;
                }
                Mat resizedCocktailImg;
                resize(cocktailImg,resizedCocktailImg,Size(200,200));
                blendImage(cocktailBackground,resizedCocktailImg);
                cvui::image(description_window,260,10,cocktailBackground);
                cvui::update();
                imshow("description window",description_window);
                if(waitKey(0)==27)destroyWindow("description window");
            }
            else if(clickedCocktail == -2) break; //if redetect button was clicked, restart program
            if(waitKey(2000)==27)break;
        }
    }
    return 0;
}
void draw_label(Mat& input_image, string label, int left, int top)
{
    // Display the label at the top of the bounding box.
    int baseLine;
    Size label_size = getTextSize(label, FONT_FACE, FONT_SCALE, THICKNESS, &baseLine);
    top = max(top, label_size.height);
    // Top left corner.
    Point tlc = Point(left, top);
    // Bottom right corner.
    Point brc = Point(left + label_size.width, top + label_size.height + baseLine);
    // Draw white rectangle.
    rectangle(input_image, tlc, brc, BLACK, FILLED);
    // Put the label on the black rectangle.
    putText(input_image, label, Point(left, top + label_size.height), FONT_FACE, FONT_SCALE, YELLOW, THICKNESS);
}
vector<Mat> pre_process(Mat &input_image, Net &net){
    // Convert to blob.
    Mat blob = blobFromImage(input_image, 1./255., Size(INPUT_WIDTH, INPUT_HEIGHT), Scalar(), true, false);
    net.setInput(blob);

    // Forward propagate.
    vector<Mat> outputs;
    net.forward(outputs, net.getUnconnectedOutLayersNames());
    return outputs;
}
Mat post_process(Mat &input_image, vector<Mat> &outputs, const vector<string> &clsname){
    // Initialize vectors to hold respective outputs while unwrapping detections.
    vector<int> class_ids;
    vector<float> confidences;
    vector<Rect> boxes;
    // Resizing factor.
    float x_factor = input_image.cols / INPUT_WIDTH;
    float y_factor = input_image.rows / INPUT_HEIGHT;
    float *data = (float *)outputs[0].data;
    const int dimensions = 15;//0~4 : xywh,5:confidence level, 6~14 : classes
    // 25200 for default size 640.
    const int rows = 25200;
    // Iterate through 25200 detections.
    for (int i = 0; i < rows; ++i){
        float confidence = data[4];
        // Discard bad detections and continue.
        if (confidence >= CONFIDENCE_THRESHOLD){
            float * classes_scores = data + 5;
            // Create a 1x15 Mat and store class scores of 10 classes.
            Mat scores(1, clsname.size(), CV_32FC1, classes_scores);
            // Perform minMaxLoc and acquire the index of best class  score.
            Point class_id;
            double max_class_score;
            minMaxLoc(scores, 0, &max_class_score, 0, &class_id);
            // Continue if the class score is above the threshold.
            if (max_class_score > SCORE_THRESHOLD){
                // Store class ID and confidence in the pre-defined respective vectors.
                confidences.push_back(confidence);
                class_ids.push_back(class_id.x);
                // Center.
                float cx = data[0];
                float cy = data[1];
                // Box dimension.
                float w = data[2];
                float h = data[3];
                // Bounding box coordinates.
                int left = int((cx - 0.5 * w) * x_factor);
                int top = int((cy - 0.5 * h) * y_factor);
                int width = int(w * x_factor);
                int height = int(h * y_factor);
                // Store good detections in the boxes vector.
                boxes.push_back(Rect(left, top, width, height));
            }
        }
        // Jump to the next row.
        data += 15;
    }
    // Perform Non-Maximum Suppression and draw predictions.
    vector<int> indices;
    NMSBoxes(boxes, confidences, SCORE_THRESHOLD, NMS_THRESHOLD, indices);
    for(int i=0;i<indices.size();i++){
        cout<<"index : "<<class_ids[indices[i]]<<" - "<<clsname[class_ids[indices[i]]]<<'\n'<<flush;
        DLlist.push_back(class_ids[indices[i]]);
    }
    for(int i = 0; i < indices.size(); i++){
        int idx = indices[i];
        Rect box = boxes[idx];
        int left = box.x;
        int top = box.y;
        int width = box.width;
        int height = box.height;
        // Draw bounding box.
        rectangle(input_image, Point(left, top), Point(left + width, top + height), BLUE, 3*THICKNESS);
        // Get the label for the class name and its confidence.
        string label = format("%.2f", confidences[idx]);
        label = clsname[class_ids[idx]] + ":" + label;
        // Draw class labels.
        draw_label(input_image, label, left, top);
    }
    return input_image;
}
vector<string> csv_read_row(istream &file, char delimiter){
    stringstream ss;
    vector<string> row;
    while(file.good()){
        char c = file.get();
        if(c=='"'){
            if(file.peek()=='"')ss<<(char)file.get();
        }
        else if (c==delimiter){
            row.push_back(ss.str());
            ss.str(""); //initiate when meets delimiter
        }
        else if(c=='\r' || c=='\n'){
            if(file.peek()=='\n')file.get();
            row.push_back(ss.str());
            return row;
        }
        else ss<<c;
    }
    row.push_back(ss.str());
    int lastrowlength = row[row.size()-1].length();
    row[row.size()-1][lastrowlength-1]='\0';
    return row;
};
int getClickedCocktail(int possibleCocktailNum, Point cursor){
    if(cursor.x >= 10 && cursor.x <= 360 && cursor.y >= 200 && cursor.y <= 200 + 25 * (possibleCocktailNum + 1)){
        return ((cursor.y - 200) / 25);
    }
    else if(cursor.x >= 650 && cursor.x <= 800 && cursor.y >= 150 && cursor.y <= 185) return -2; //redetect
    else return -1;
};
void blendImage(Mat background, Mat image) {
    // blend image into background (image over background)
    // background is fully opaque (don't have alpha channel, so must have 3 channels)

    int bgStartX = 0, bgStartY = 0;

    // get the sub-area for blending in background
    Mat blendMat = background(Range(bgStartY, bgStartY + image.rows),Range(bgStartX, bgStartX + image.cols));

    for (int y = 0; y < image.rows; ++y) {
        for (int x = 0; x < image.cols; ++x) {
            Vec3b& backgroundPixel = blendMat.at<Vec3b>(y, x);
            Vec4b& imagePixel = image.at<Vec4b>(y, x);

            // get alpha value (divide 255 since the image of alpha value is 0 to 255. Change it to 0.0-1.0)
            float alpha = imagePixel[3] / 255.;

            backgroundPixel[0] = saturate_cast<uchar>(alpha * imagePixel[0] + (1.0 - alpha) * backgroundPixel[0]);
            backgroundPixel[1] = saturate_cast<uchar>(alpha * imagePixel[1] + (1.0 - alpha) * backgroundPixel[1]);
            backgroundPixel[2] = saturate_cast<uchar>(alpha * imagePixel[2] + (1.0 - alpha) * backgroundPixel[2]);
        }
    }
};