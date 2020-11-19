#ifndef __CONSTANTS_HPP__
#define __CONSTANTS_HPP__
#include "VBOHelper.hpp"

namespace duffte
{
    enum constant{
        vertSize = sizeof(duffte::vertPos) / sizeof(duffte::vertPos::x),
        texSize = sizeof(duffte::texPos) / sizeof(duffte::texPos::x),
        vertOffset = 0,
        texOffset = sizeof(duffte::vertPos),
        coordStride = sizeof(duffte::vboCoords)
    };
} //namespace duffte

#endif // __CONSTANTS_H__