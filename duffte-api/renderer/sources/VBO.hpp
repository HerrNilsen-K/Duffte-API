#ifndef __VBO_HPP__
#define __VBO_HPP__

#include "vboImpl.hpp"
#include "VBOHelper.hpp"
#include <optional>

namespace duffte
{
    class VBO
    {
    private:
        std::optional<duffte::vboImpl> m_vboContainer;

    public:
        VBO();
        ~VBO();

        //Bind the buffer
        void bind();
        //Unbind the buffer
        void unbind();
        //Fill buffer with data
        VBO &data(vboCoords *coords, int coordsNum);
    };
} // namespace duffte

#endif // __VBO_H__