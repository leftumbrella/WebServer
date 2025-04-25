#include <iostream>
#include "Utils.h"
int main(){
    auto img = Captchpublic::GetImage(4);
    cv::imwrite("./code.jpg",img.second);
    return 0;
}