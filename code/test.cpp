#include <iostream>
#include <opencv4/opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main()
{
    cout << "Hello" << endl;
    Mat img = imread("../image/yangzi.jpg");
    imshow("imgInput", img);
    waitKey(0);
    return 0;
}