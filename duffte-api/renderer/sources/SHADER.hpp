#ifndef __SHADER_HPP__
#define __SHADER_HPP__
#include <string>

namespace duffte
{
    class SHADER
    {
    private:
       unsigned int m_shaderProgram; 
    public:
        SHADER(const char *vertex, const char *fragment);
        ~SHADER();

        void use();
    };
} // namespace duffte

#endif // __SHADER_H__