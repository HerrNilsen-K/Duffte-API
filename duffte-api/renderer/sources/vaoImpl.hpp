#ifndef __VAOIMPL_HPP__
#define __VAOIMPL_HPP__

namespace duffte
{
    class vaoImpl
    {
    private:
        unsigned int m_vao;
        short m_vertexArrayAttributeCounter;

    public:
        vaoImpl();
        ~vaoImpl();

        void bind();
        void unbind();

        void push(int size, int stride, int offset);
        void enableVertexArray();
    };
} // namespace duffte

#endif // __VAOIMPL_H__