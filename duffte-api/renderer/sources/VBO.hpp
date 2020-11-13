#ifndef __VBO_HPP__
#define __VBO_HPP__

#include "VBOHelper.hpp"

namespace duffte
{
    class VBO
    {
    private:
        unsigned int m_buffer;

    public:
        VBO() = delete;
        VBO(vboCoords *coords, int coordsNum);
        ~VBO();

        //Bind the buffer
        void bind();
        //Unbind the buffer
        void unbind();
    };
} // namespace duffte

#endif // __VBO_H__