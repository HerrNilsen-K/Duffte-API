#include "VAO.hpp"
#include <GL/glew.h>
#include <iostream>

namespace duffte
{
    VAO::VAO()
    {
    }

    VAO::~VAO()
    {
    }

    void VAO::bind()
    {
        m_vaoContainer.value().bind();
    }

    void VAO::unbind()
    {
        m_vaoContainer.value().unbind();
    }

    VAO &VAO::push(int p_size, int p_stride, int p_offset)
    {
        static bool first = true;
        if (first)
        {
            m_vaoContainer.emplace();   //Emplace only on the first push call
            first = !first;
        }
        m_vaoContainer.value().push(p_size, p_stride, p_offset);
        return *this;
    }

    void VAO::enableVertexArray()
    {
        m_vaoContainer.value().enableVertexArray();
    }
} // namespace duffte