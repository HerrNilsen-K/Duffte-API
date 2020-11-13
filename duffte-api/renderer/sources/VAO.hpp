#ifndef __VAO_HPP__
#define __VAO_HPP__

namespace duffte
{
    class VAO
    {
    private:
        unsigned int m_vao;
        short m_vertexArrayAttributeCounter;

    private:
        void enableVertexArray();

    public:
        VAO();
        ~VAO();

        void bind();
        void unbind();

        void push(int size, int stride);
    };
} // namespace duffte

#endif // __VAO_H__