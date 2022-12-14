/**
 * @file pyCapture.hpp
 * @author B
 * @brief Python to CPP image capturer
 * @version 0.1
 */

#include <Python.h>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <string>
#include "base64.h"


class pyCapture
{
private:

    PyObject *pName, *pModule, *pFunc;
    PyObject *pArgs, *pArg, *pResult;

    cv::Mat decodedImage_;

public:
    pyCapture();
    ~pyCapture();

    cv::Mat getImage();
};

