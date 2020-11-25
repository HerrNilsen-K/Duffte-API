#include "TEXTURE.hpp"

namespace duffte
{
    TEXTURE::TEXTURE()
    {
    }

    TEXTURE::~TEXTURE()
    {
    }

    void TEXTURE::path(const char *p_imagePath)
    {
        static bool first = true;
        if (first)
        {
            m_txtureContainer.emplace();
            first = !first;
        }
        m_txtureContainer.value().path(p_imagePath);
    }

    void TEXTURE::bind()
    {
        m_txtureContainer.value().bind();
    }

    void TEXTURE::ubnind()
    {
        m_txtureContainer.value().unbind();
    }
} // namespace duffte