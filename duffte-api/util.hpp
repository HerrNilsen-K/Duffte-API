#ifndef __UTIL_HPP__
#define __UTIL_HPP__

#include <iostream>

// Error log for debuging

template <class T> constexpr void ERROR_LOG(T x) {
  std::cout << (x) << std::endl
            << "File: " << __FILE__ << std::endl
            << "Line: " << __LINE__ << std::endl;
}
#endif // __UTIL_H__