#ifndef __UTIL_HPP__
#define __UTIL_HPP__

#include <iostream>

//Error log for debuging
#define ERROR_LOG(x)                                 \
    std::cout << (x) << ' ' << __FILE__ << std::endl \
              << __LINE__ << std::endl

#endif // __UTIL_H__