#ifndef __VBO_HPP__
#define __VBO_HPP__

namespace duffte
{
    class VBO
    {
    private:
        unsigned int m_buffer;

    public:
        VBO();
        ~VBO();

        //Bind the buffer
        void bind();
        //Unbind the buffer
        void unbind();
    };
} // namespace duffte

#endif // __VBO_H__