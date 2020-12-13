#ifndef __SHADERIMPL_HPP__
#define __SHADERIMPL_HPP__

#include <string>
#include <glm/mat4x4.hpp>

namespace duffte
{
    class shaderImpl
    {
    public:
        unsigned int m_shaderProgram;

    public:
        shaderImpl();
        ~shaderImpl();

        //Create the program
        void shaders(const char *vertex, const char *fragment);
        void use();
        //Uniform setters
        void setVec(const char *name, float p1, float p2);
        void setVec(const char *name, float p1, float p2, float p3);
        void setVec(const char *name, float p1, float p2, float p3, float p4);

        void setMat(const char *name, glm::mat4 matrix);
    };
} // namespace duffte

#endif // __SHADERIMPL_HPP__