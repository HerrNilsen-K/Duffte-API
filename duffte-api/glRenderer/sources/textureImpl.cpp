#include "textureImpl.hpp"
#define GLEW_STATIC       
#include <GL/glew.h>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_STATIC
#ifdef _WIN32
#include <stb_image.h>
#else
#include <stb/stb_image.h>
#endif
namespace duffte
{
    textureImpl::textureImpl()
    {
        glGenTextures(1, &m_texture);
        stbi_set_flip_vertically_on_load(true);
    }

    textureImpl::~textureImpl()
    {
        this->unbind();
        glDeleteTextures(1, &m_texture);
    }

    void textureImpl::path(const char *p_imagePath)
    {
        this->bind();
        int width, height, colorChannels;
        unsigned char *data = stbi_load(p_imagePath, &width, &height, &colorChannels, 0);
        if (!data)
        {
            std::cout << "Failed to load texture\n";
            return;
        }
        if (colorChannels == 3)
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        else
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(data);
    }

    void textureImpl::bind()
    {
        glBindTexture(GL_TEXTURE_2D, m_texture);
    }

    void textureImpl::unbind()
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }
} // namespace duffte