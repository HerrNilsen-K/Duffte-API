#include "vboImpl.hpp"
#include "../../util.hpp"
#define GLEW_STATIC       
#include <GL/glew.h>
#include "VBOHelper.hpp"
#include <iostream>

namespace duffte
{
    vboImpl::vboImpl()
    {
        glGenBuffers(1, &m_buffer);
    }

    vboImpl::~vboImpl()
    {
        unbind();
        glDeleteBuffers(1, &m_buffer);
    }

    vboImpl &vboImpl::data(vboCoords *p_coords, int p_coordsNum)
    {
        bind();
        glBufferData(GL_ARRAY_BUFFER,
                     (GLsizeiptr)sizeof(vboCoords) * p_coordsNum,
                     p_coords,
                     GL_STATIC_DRAW);
        return *this;
    }

    void vboImpl::bind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_buffer);
    }

    void vboImpl::unbind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
} // namespace duffte