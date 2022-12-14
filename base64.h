/**
 * @file base64.hpp
 * @author B
 * @brief Base64 Header
 * @version 0.1
 */


#ifndef _BASE64_H_
#define _BASE64_H_
#include <string>
std::string base64_encode(unsigned char const* , unsigned int len);
std::string base64_decode(std::string const& s);
#endif 