#ifndef __SHADERIMPL_HPP__
#define __SHADERIMPL_HPP__

#include <string>

namespace duffte
{
    class shaderImpl
    {
    private:
        unsigned int m_shaderProgram;

    public:
        shaderImpl();
        ~shaderImpl();

        void shaders(const char *vertex, const char *fragment);
        void use();

        void setVec(const char *name, float p1, float p2);
        void setVec(const char *name, float p1, float p2, float p3);
        void setVec(const char *name, float p1, float p2, float p3, float p4);
    };
} // namespace duffte

#endif // __SHADERIMPL_HPP__