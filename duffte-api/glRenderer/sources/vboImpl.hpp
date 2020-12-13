#ifndef __VBOIMPL_HPP__
#define __VBOIMPL_HPP__

#include "VBOHelper.hpp"

namespace duffte
{
    class vboImpl
    {
    private:
        unsigned int m_buffer;

    public:
        vboImpl();
        ~vboImpl();

        //Bind the buffer
        void bind();
        //Unbind the buffer
        void unbind();
        //Fill buffer with data
        vboImpl &data(float *coords, int coordsNum);
    };
} // namespace duffte

#endif // __VBOIMPL_HPP__