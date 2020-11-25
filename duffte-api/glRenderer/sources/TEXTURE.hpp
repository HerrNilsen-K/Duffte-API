#ifndef __TEXTURE_HPP__
#define __TEXTURE_HPP__

#include "textureImpl.hpp"
#include <optional>

namespace duffte
{
    class TEXTURE
    {
    private:
        std::optional<duffte::textureImpl> m_txtureContainer;
        public:
        TEXTURE();
        ~TEXTURE();

        void path(const char *imagePath);

        void bind();
        void ubnind();
    };
} // namespace duffte

#endif // __TEXTURE_HPP__