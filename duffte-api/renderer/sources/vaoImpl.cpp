#include "vaoImpl.hpp"
#include <GL/glew.h>
#include <iostream>

namespace duffte
{
    vaoImpl::vaoImpl()
        : m_vertexArrayAttributeCounter(0)
    {
        glGenVertexArrays(1, &m_vao);
    }

    vaoImpl::~vaoImpl()
    {
        unbind();
        glDeleteVertexArrays(1, &m_vao);
    }

    void vaoImpl::bind()
    {
        glBindVertexArray(m_vao);
    }

    void vaoImpl::unbind()
    {
        glBindVertexArray(0);
    }

    void vaoImpl::push(int p_size, int p_stride, int p_offset)
    {
        std::cout << p_size << ' ' << p_stride << ' ' << p_offset << std::endl;
        glVertexAttribPointer(m_vertexArrayAttributeCounter,
                              p_size, GL_FLOAT,
                              false, p_stride, reinterpret_cast<void *>(p_offset));
        enableVertexArray();
        m_vertexArrayAttributeCounter++;
    }

    void vaoImpl::enableVertexArray()
    {
        glEnableVertexAttribArray(m_vertexArrayAttributeCounter);
    }
} // namespace duffte