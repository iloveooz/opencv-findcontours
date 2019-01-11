#include <iostream>
#include <cv.h>
#include <cv.hpp>
#include <opencv2/imgcodecs.hpp>

int main() {
    // читаем изображение
    cv::Mat img0 = cv::imread("../images/apple.jpg", 1);

    cv::Mat img1;

    // преобразуем RGB изображение в оттенки серого
    cv::cvtColor(img0, img1, CV_RGB2GRAY);

    // применяем фильтр canny
    

    // показываем изображение
    cv::imshow("original", img0);
    cv::imshow("canny", img1);

    // ожидание нажатия клавиши
    cv::waitKey(0);

    // сохраняем изображения
    cv::imwrite("../images/apple_canny.jpg", img1);
    return 0;
}