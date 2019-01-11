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
    cv::Mat crop(img0.rows, img0.cols, CV_8UC3);

    // делаем задний фон зелёным
    crop.setTo(cv::Scalar(128, 128, 128));

    // создаём результирующее изображени
    img0.copyTo(crop, mask);

    // нормализуем маску
    cv::normalize(mask.clone(), mask, 0.0, 255.0, CV_MINMAX, CV_8UC1);

    // показываем изображение
    cv::imshow("original", img0);
    cv::imshow("mask", mask);
    cv::imshow("canny", img1);
    cv::imshow("cropped", crop);

    // ожидание нажатия клавиши
    cv::waitKey(0);

    // сохраняем изображения
    cv::imwrite("../images/apple_canny.jpg", img1);
    cv::imwrite("../images/mask.jpg", mask);
    cv::imwrite("../images/apple_cropped.jpg", crop);
    return 0;
}