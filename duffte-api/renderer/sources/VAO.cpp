#include "VAO.hpp"
#include <GL/glew.h>
#include <iostream>

namespace duffte
{
    VAO::VAO()
        : m_vertexArrayAttributeCounter(0)
    {
        glGenVertexArrays(1, &m_vao);
    }

    VAO::~VAO()
    {
    }

    void VAO::bind()
    {
        glBindVertexArray(m_vao);
    }

    void VAO::unbind()
    {
        glBindVertexArray(0);
    }

    void VAO::push(int p_size, int p_stride, int p_offset)
    {
        std::cout << p_size << ' ' << p_stride << std::endl;
        enableVertexArray();
        glVertexAttribPointer(m_vertexArrayAttributeCounter,
                              p_size, GL_FLOAT,
                              false, p_stride, (void *)p_offset);
        m_vertexArrayAttributeCounter++;
    }

    void VAO::enableVertexArray()
    {
        glEnableVertexAttribArray(m_vertexArrayAttributeCounter);
    }
} // namespace duffte