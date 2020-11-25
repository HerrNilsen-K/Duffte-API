#ifndef __TEXTUREIMPL_HPP__
#define __TEXTUREIMPL_HPP__

namespace duffte
{
    class textureImpl
    {
    private:
        unsigned int m_texture;

    public:
        textureImpl();
        ~textureImpl();

void path(const char *imagePath);

        void bind();
        void unbind();
    };
} // namespace duffte

#endif // __TEXTUREIMPL_HPP__