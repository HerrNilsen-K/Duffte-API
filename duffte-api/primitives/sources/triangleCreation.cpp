#include "triangleCreation.hpp"
#include <iostream>

namespace duffte {
trinagleCreation::trinagleCreation() {
  float vertecies[] = {0.0f, 1.0f, 0.0f, 1.0f, -1.0f, 0.0f, -1.0f, -1.0f, 0.0f};

  const char *vertexShaderSource =
      "#version 330 core\n"
      "layout (location = 0) in vec3 aPos;\n"

      "uniform vec2 first;\n"
      "uniform vec2 second;\n"
      "uniform vec2 third;\n"

      "uniform mat4 model;\n"
      "uniform mat4 view;\n"
            "uniform mat4 projection;\n"

            "void main()\n"
            "{\n"
            "   if(gl_VertexID == 0)"
            "       gl_Position = view * projection * vec4(first, 0, 1);\n"
            "   else if(gl_VertexID == 1)"
            "       gl_Position = view * projection * vec4(second, 0, 1);\n"
            "   else"
            "       gl_Position = view * projection * vec4(third, 0, 1);\n"
            "}\0";

        const char *fragmentShaderSource =
            "#version 330 core\n"
            "out vec4 FragColor;\n"

            "uniform vec3 color;\n"

            "void main()\n"
            "{\n"
            "   FragColor = vec4(color, 1);\n"
            "}\n\0";

        m_vbo.data(vertecies, sizeof(vertecies) / sizeof(*vertecies));
        m_vao.push(duffte::constant::vertSize, 12, duffte::constant::vertOffset);
        m_shader.shaders(vertexShaderSource, fragmentShaderSource);
    }

} // namespace duffte