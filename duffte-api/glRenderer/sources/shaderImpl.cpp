#include "shaderImpl.hpp"
#define GLEW_STATIC
#include <GL/glew.h>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace duffte
{
    shaderImpl::shaderImpl()
    {
        m_shaderProgram = glCreateProgram();
    }

    shaderImpl::~shaderImpl()
    {
        glDeleteProgram(m_shaderProgram);
    }

    void shaderImpl::shaders(const char *p_vertex, const char *p_fragment)
    {
        int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &p_vertex, NULL);
        glCompileShader(vertexShader);
        // check for shader compile errors
        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                      << infoLog << std::endl;
        }
        // fragment shader
        int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &p_fragment, NULL);
        glCompileShader(fragmentShader);
        // check for shader compile errors
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
                      << infoLog << std::endl;
        }
        // link shaders
        glAttachShader(m_shaderProgram, vertexShader);
        glAttachShader(m_shaderProgram, fragmentShader);
        glLinkProgram(m_shaderProgram);
        // check for linking errors
        glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(m_shaderProgram, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                      << infoLog << std::endl;
        }
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        use();
    }

    void shaderImpl::use()
    {
        glUseProgram(m_shaderProgram);
    }

    void shaderImpl::setVec(const char *p_name, float p_p1, float p_p2)
    {
        glUniform2f(glGetUniformLocation(this->m_shaderProgram, p_name), p_p1, p_p2);
    }

    void shaderImpl::setVec(const char *p_name, float p_p1, float p_p2, float p_p3)
    {
        glUniform3f(glGetUniformLocation(this->m_shaderProgram, p_name), p_p1, p_p2, p_p3);
    }

    void shaderImpl::setVec(const char *p_name, float p_p1, float p_p2, float p_p3, float p_p4)
    {
        glUniform4f(glGetUniformLocation(this->m_shaderProgram, p_name), p_p1, p_p2, p_p3, p_p4);
    }

    void shaderImpl::setMat(const char *p_name, glm::mat4 p_matrix)
    {
        glUniformMatrix4fv(glGetUniformLocation(this->m_shaderProgram, p_name), 1, GL_FALSE, glm::value_ptr(p_matrix));
    }
} // namespace duffte