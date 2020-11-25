#ifndef __SHADER_HPP__
#define __SHADER_HPP__

#include "shaderImpl.hpp"
#include <optional>
#include <GLM/mat4x4.hpp>

namespace duffte
{
    class SHADER
    {
    public:
        std::optional<duffte::shaderImpl> m_shaderContainer;

    public:
        SHADER();
        ~SHADER();
//Create the program
        void shaders(const char *vertex, const char *fragment);
        void use();

//Set uniforms
        void setVec(const char *name, float p1, float p2);
        void setVec(const char *name, float p1, float p2, float p3);
        void setVec(const char *name, float p1, float p2, float p3, float p4);

        void setMat(const char *name, glm::mat4 matrix);
    };
} // namespace duffte

#endif // __SHADER_H__