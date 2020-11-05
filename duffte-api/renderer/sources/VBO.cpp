#include "VBO.hpp"
#include "../../util.hpp"
#include <GL/glew.h>

namespace duffte
{
    VBO::VBO()
    {
        glGenBuffers(1, &m_buffer);
        bind();
    }

    VBO::~VBO()
    {
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