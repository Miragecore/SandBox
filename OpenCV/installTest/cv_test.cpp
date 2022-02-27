#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <string>

using namespace cv;

int main(int argc, char*argv[]){

    if(argc != 2)
    {
        printf("input img path\n");
    }

    Mat img;

    VideoCapture cap(0);

    if(!cap.isOpened())
    {
        printf("Cam not opened\n");
        return -1;
    }

    namedWindow("tt", WINDOW_AUTOSIZE);

    int key = 1;
    int count = 0;
    std::string fn;
    while(1){
        cap >> img;

        imshow("tt", img);

        key = waitKey(1);
        //if ESC
        if(key == 27)
            break;
        //if ENTER
        if(key == 13){
            fn = "./test" + std::to_string(count++) + ".jpg";
            cvtColor(img, img, COLOR_BGR2GRAY);
            //save gray image
            imwrite(fn, img);
        }
        //to checking a key
        if(key != -1)
            printf("%d\n", key);
    }

    return 0;
}
