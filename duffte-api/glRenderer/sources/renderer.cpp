#include "renderer.hpp"
#include "GL/glew.h"
#include <iostream>

namespace duffte
{
    void renderer::rawRendering(VBO &p_vbo, VAO &p_vao, SHADER &p_shader, unsigned int p_vertecies)
    {
        p_vbo.bind();
        p_vao.bind();
        p_shader.use();
        glDrawArrays(GL_TRIANGLES, 0, p_vertecies);
    }
} // namespace duffte