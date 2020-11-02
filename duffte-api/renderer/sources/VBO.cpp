#include "VBO.hpp"
#include <GL/glew.h>

VBO::VBO() 
{
    glGenBuffers(1, &m_buffer);
}

VBO::~VBO() 
{
    
}

void VBO::bind(){
    glBindBuffer(GL_ARRAY_BUFFER, m_buffer);
}

void VBO::unbind(){
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}