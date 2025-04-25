#ifndef UTILS_H
#define UTILS_H
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <random>
class Captchpublic{
    public:
        static std::pair<std::string,cv::Mat> GetImage(std::size_t sizeWord){
            std::pair<std::string,cv::Mat> pairCaptch;
            std::string charset = "ABCDEFGHJKMNPQRSTUVWXYZabcdefghjkmnpqrstuvwxyz123456789";
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(0, charset.size() - 1);

            for (int i = 0; i < sizeWord; ++i) {
                pairCaptch.first += charset[dis(gen)];
            }

            // 创建一个空白的图像
            int width = 200;
            int height = 60;
            cv::Mat image(height, width, CV_8UC3, cv::Scalar(255, 255, 255));

            // 设置字体
            int font = cv::FONT_HERSHEY_SIMPLEX;
            double fontScale = 1.5;
            int thickness = 2;

            // 获取验证码字符串的宽高
            cv::Size textSize = cv::getTextSize(pairCaptch.first, font, fontScale, thickness, 0);
            cv::Point textOrg((width - textSize.width) / 2, (height + textSize.height) / 2);

            // 在图像上绘制文本
            putText(image, pairCaptch.first, textOrg, font, fontScale, cv::Scalar(0, 0, 0), thickness);

            // 可选：在图像上添加一些噪声（随机线条、干扰点等）
            std::uniform_int_distribution<> dist_x(0, width);
            std::uniform_int_distribution<> dist_y(0, height);
            std::uniform_int_distribution<> dist_color(0, 255);
            for (int i = 0; i < 5; ++i) {
                line(image, cv::Point(dist_x(gen), dist_y(gen)), cv::Point(dist_x(gen), dist_y(gen)), cv::Scalar(dist_color(gen), dist_color(gen), dist_color(gen)), 1);
            }
            for (int i = 0; i < 100; ++i) {
                image.at<cv::Vec3b>(dist_y(gen), dist_x(gen)) = cv::Vec3b(dist_color(gen), dist_color(gen), dist_color(gen));
            }

            pairCaptch.second = image;
            return pairCaptch;
        }
};

#endif //UTILS_H