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
    };
} // namespace duffte

#endif // __SHADERIMPL_HPP__