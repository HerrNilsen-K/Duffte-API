#include "SHADER.hpp"
#include <GL/glew.h>
#include <iostream>
#include <assert.h>
namespace duffte
{
    SHADER::SHADER()
    {
    }

    SHADER::~SHADER()
    {
    }

    void SHADER::shaders(const char *p_vertex, const char *p_fragment)
    {
        static bool first = true;
        if (first)
        {
            m_shaderContainer.emplace();
            first = !first;
        }
        m_shaderContainer.value().shaders(p_vertex, p_fragment);
    }

    void SHADER::use()
    {
        m_shaderContainer.value().use();
    }
} // namespace duffte