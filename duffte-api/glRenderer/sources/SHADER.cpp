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
    
    void SHADER::setVec(const char *name, float p_p1, float p_p2) 
    {
       m_shaderContainer.value().setVec(name, p_p1, p_p2); 
    }
    
    void SHADER::setVec(const char *name, float p_p1, float p_p2, float p_p3) 
    {
        
       m_shaderContainer.value().setVec(name, p_p1, p_p2, p_p3); 
    }
    
    void SHADER::setVec(const char *name, float p_p1, float p_p2, float p_p3, float p_p4) 
    {
        
       m_shaderContainer.value().setVec(name, p_p1, p_p2, p_p3, p_p4); 
    }
    
    void SHADER::setMat(const char *p_name, glm::mat4 p_matrix) 
    {
       m_shaderContainer.value().setMat(p_name, p_matrix); 
    }
} // namespace duffte