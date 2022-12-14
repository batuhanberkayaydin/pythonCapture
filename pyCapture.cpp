/**
 * @file pyCapture.cpp
 * @author B
 * @brief Python to CPP image capturer
 * @version 0.1
 */

#include "pyCapture.hpp"

pyCapture::pyCapture(){

    setenv("PYTHONPATH", ".", 0);
    Py_Initialize();
}

pyCapture::~pyCapture(){

    Py_Finalize();
}

cv::Mat pyCapture::getImage(){

    pName = PyUnicode_FromString("capture");

    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        pFunc = PyObject_GetAttrString(pModule, "get_frames");

        if (pFunc) {
            pArgs = PyTuple_New(1);
            pArg = PyUnicode_FromString("0");

            PyTuple_SetItem(pArgs, 0, pArg);
            pResult = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);
            if (pResult != NULL) {

                char* str = PyBytes_AS_STRING(pResult);
                
                const std::string base64_chars = std::string(str);
                std::string s = base64_decode(base64_chars);                

                char* str3 = (char*)s.c_str();
                size_t len = s.size();
                uchar* str2 = reinterpret_cast<unsigned char*>(str3);

                cv::Mat rawData(1, len*sizeof(uchar), CV_8UC1, str2);
                decodedImage_  =  cv::imdecode(rawData, cv::IMREAD_COLOR);

                Py_DECREF(pResult);

            }
            else {
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                PyErr_Print();
                fprintf(stderr,"Call failed\n");
            }
        }
        else {
            if (PyErr_Occurred())
                PyErr_Print();
            fprintf(stderr, "Cannot find function");
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    else {
        PyErr_Print();
        fprintf(stderr, "Failed to load module");
    }

    return decodedImage_;

}
