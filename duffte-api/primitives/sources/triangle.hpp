#ifndef __TRIANGLE_HPP__
#define __TRIANGLE_HPP__

struct __colorContainer
{
    float r, g, b;
};


namespace duffte{
    void triangle2D(float x1, float y1, float x2, float y2, float x3, float y3,float x, float y, __colorContainer color = {1, 1, 1});
}

#endif // __TRIANGLE_HPP__