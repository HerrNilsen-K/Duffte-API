#ifndef __UTIL_HPP__
#define __UTIL_HPP__

#include <iostream>

//Error log for debuging
#define ERROR_LOG(x)                               \
    std::cout << (x) << std::endl                  \
              << "File: " << __FILE__ << std::endl \
              << "Line: " << __LINE__ << std::endl

#endif // __UTIL_H__