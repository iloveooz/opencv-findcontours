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
    cv::Canny(img1, img1, 100, 200);

    // находим контуры
    std::vector <std::vector<cv::Point> > contours;
    cv::findContours(img1, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

    // создаём маску
    cv::Mat mask = cv::Mat::zeros(img1.rows, img1.cols, CV_8UC1);

    // CV_FILLED заполняет найденные компоненты
    cv::drawContours(mask, contours, -1, cv::Scalar(255), CV_FILLED);

    // создаём ещё одно изображение


    // показываем изображение
    cv::imshow("original", img0);
    cv::imshow("mask", mask);
    cv::imshow("canny", img1);

    // ожидание нажатия клавиши
    cv::waitKey(0);

    // сохраняем изображения
    cv::imwrite("../images/apple_canny.jpg", img1);
    cv::imwrite("../images/mask.jpg", mask);
    return 0;
}