#include <iostream>
#include <cv.h>
#include <cv.hpp>
#include <opencv2/imgcodecs.hpp>

int main() {
    // читаем изображение
    cv::Mat img0 = cv::imread("../images/apple.jpg", 1);

    // показываем изображение
    cv::imshow("original", img0);

    cv::waitKey(0);

    return 0;
}