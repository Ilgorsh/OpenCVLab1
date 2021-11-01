#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int main()
{
    Mat image = imread("Hatkid.jpg");
    if (image.empty()) {
        cout << "Open error \n";
        cin.get();
        return  -1;
    }
    String WindowName = "SMUG WINDOW";
    namedWindow(WindowName);
    imshow(WindowName, image);
    imwrite("Default.jpg", image);
    waitKey(0);
    Mat black_and_white;
    cvtColor(image, black_and_white, COLOR_RGB2GRAY);
    WindowName = "SMUG WINDOW BNW";
    namedWindow(WindowName);
    imshow(WindowName, black_and_white);
    imwrite("BnW.jpg", black_and_white);
    waitKey(0);
    Mat blured;
    int ksize = 15;
    GaussianBlur(image,blured, Size(ksize, ksize),3,3);
    WindowName = "SMUG WINDOW BLURED";
    namedWindow(WindowName);
    imshow(WindowName, blured);
    imwrite("Blured.jpg",blured);
    waitKey(0);
    Mat negative;
    bitwise_not(image, negative);
    WindowName = "SMUG WINDOW NEGATIVE";
    namedWindow(WindowName);
    imshow(WindowName, negative);
    waitKey(0);
    Mat c565;
    cvtColor(image,c565, COLOR_RGB2YCrCb);
    WindowName = "SMUG WINDOW Yelllow";
    namedWindow(WindowName);
    imshow(WindowName, c565);
    imwrite("Yellow.jpg", c565);
    waitKey(0);
    WindowName = "SMUG CONTOUR 565";
    Mat canny;
    Canny(black_and_white, canny, 20, 100, 3, false);
    namedWindow(WindowName);
    imshow(WindowName, canny);
    imwrite("Contour.jpg", canny);
    waitKey(0);
    WindowName = "SMUG WINDOW HOUGH";
    Mat hough;
    vector<Vec4i> lines;
    HoughLinesP(canny, lines, 1, CV_PI/180 , 30);
    cvtColor(canny, canny, COLOR_GRAY2BGR);
    for (size_t i = 0; i < lines.size(); i++)
    {
        line(canny, Point(lines[i][0], lines[i][1]),
            Point(lines[i][2], lines[i][3]), Scalar(0, 0, 255), 3, 8);
    }
    namedWindow(WindowName,1);
    imshow(WindowName, canny);
    imwrite("Lines.jpg", canny);
    waitKey(0);
    return 0;
}
