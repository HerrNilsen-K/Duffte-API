#ifndef __SHADER_HPP__
#define __SHADER_HPP__

#include "shaderImpl.hpp"
#include <optional>

namespace duffte
{
    class SHADER
    {
    private:
        std::optional<duffte::shaderImpl> m_shaderContainer;

    public:
        SHADER();
        ~SHADER();

        void shaders(const char *vertex, const char *fragment);
        void use();
    };
} // namespace duffte

#endif // __SHADER_H__