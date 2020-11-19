#ifndef __VAO_HPP__
#define __VAO_HPP__

#include "vaoImpl.hpp"
#include <optional>

namespace duffte
{
    class VAO
    {
    private:
        std::optional<duffte::vaoImpl> m_vaoContainer;

    private:
        void enableVertexArray();

    public:
        VAO();
        ~VAO();

        void bind();
        void unbind();

        VAO &push(int size, int stride, int offset);
    };
} // namespace duffte

#endif // __VAO_H__