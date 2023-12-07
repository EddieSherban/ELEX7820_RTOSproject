#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <thread>
#include "header.h"

//using namespace cv;

// Test functions
extern int lcd_test();
extern void spi_test();

// Extern functions
extern void do_lcd();
extern void do_spi();
//extern void lcd_init();
//extern void typeInt(int i);
//extern void typeFloat(float myFloat);
//extern void typeString();

// Globals
int _state,
    _ballX,
    _ballY,
    _car1,
    _car2,
    _score1,
    _score2;


int main(int argc, char *argv[])
{
    std::thread displayThread(do_lcd);
    displayThread.detach();

    std::thread spiThread(do_spi);
    spiThread.detach();

    cv::Mat img = cv::imread("arnold_schwarzenegger.jpg");

    if(img.empty())
       return -1;
    cv::namedWindow("arnold_schwarzenegger", cv::WINDOW_AUTOSIZE );
    cv::imshow("arnold_schwarzenegger", img);

    cv::waitKey(0);

    return 0;
}





