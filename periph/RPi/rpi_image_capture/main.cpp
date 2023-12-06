#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <thread>
#include "header.h"

//using namespace cv;

// Test functions
extern int lcd_test();

// LCD functions
extern void lcd_init();
extern void typeInt(int i);
extern void typeFloat(float myFloat);
extern void typeString();

int main(int argc, char *argv[])
{
    std::thread displayThread(lcd_test);
    displayThread.detach();

    std::thread spiThread(lcd_test);
    spiThread.detach();

    cv::Mat img = cv::imread("arnold_schwarzenegger.jpg");

    if(img.empty())
       return -1;
    cv::namedWindow("arnold_schwarzenegger", cv::WINDOW_AUTOSIZE );
    cv::imshow("arnold_schwarzenegger", img);

    cv::waitKey(0);

    return 0;
}





