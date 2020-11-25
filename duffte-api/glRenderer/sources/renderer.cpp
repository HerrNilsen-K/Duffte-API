#include "renderer.hpp"
#include "GL/glew.h"
#include <iostream>

namespace duffte
{
    void renderer::rawRendering(VBO &p_vbo, VAO &p_vao, SHADER &p_shader, TEXTURE &p_texture, unsigned int p_vertecies)
    {
        p_vbo.bind();
        p_vao.bind();
        p_shader.use();
        p_texture.bind();
        glDrawArrays(GL_TRIANGLES, 0, p_vertecies);
    }
} // namespace duffte