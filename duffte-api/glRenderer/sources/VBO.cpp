#include "VBO.hpp"
#include "../../util.hpp"
#include <GL/glew.h>
#include "VBOHelper.hpp"
#include <iostream>

namespace duffte
{
    VBO::VBO()
    {
    }

    VBO::~VBO()
    {
    }

    VBO &VBO::data(vboCoords *p_coords, int p_coordsNum)
    {
        m_vboContainer.emplace();
        m_vboContainer.value().data(p_coords, p_coordsNum);
        return *this;
    }

    void VBO::bind()
    {
        m_vboContainer.value().bind();
    }

    void VBO::unbind()
    {
        m_vboContainer.value().unbind();
    }
} // namespace duffte