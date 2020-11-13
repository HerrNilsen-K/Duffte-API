#include "VBO.hpp"
#include "../../util.hpp"
#include <GL/glew.h>
#include "VBOHelper.hpp"

namespace duffte
{
    VBO::VBO(vboCoords *p_coords, int p_coordsNum)
    {
        glGenBuffers(1, &m_buffer);
        bind();
        glBufferData(GL_ARRAY_BUFFER,
                     (GLsizeiptr)sizeof(vboCoords) * p_coordsNum,
                     (void *)&p_coords[0],
                     GL_STATIC_DRAW);
    }

    VBO::~VBO()
    {
        unbind();
        glDeleteBuffers(1, &m_buffer);
    }

    void VBO::bind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_buffer);
    }

    void VBO::unbind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
} // namespace duffte