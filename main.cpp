/**
 * @file main.cpp
 * @author Berkay
 * @brief 
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "pyCapture.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    pyCapture capt;

    cv::Mat fcaptured = capt.getImage();


    while (true) {

        cv::Mat captured = capt.getImage();
        cv::imshow("Test", captured);

        std::cout << "Rows:" << captured.rows << std::endl;
        std::cout << "cols" << captured.cols << std::endl;

        cv::waitKey(1);
    }
    capt.~pyCapture();
    return 0;
}