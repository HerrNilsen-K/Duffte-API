#include "triangle.hpp"
#include "../../util.hpp"
#include "triangleCreation.hpp"
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

duffte::trinagleCreation *triangleTemplate;

namespace duffte {
void triangle2D(float p_x1, float p_y1, float p_x2, float p_y2, float p_x3,
                float p_y3,float x, float y, __colorContainer p_color) {

  triangleTemplate->m_shader.use();
  triangleTemplate->m_shader.setVec("first", p_x1, p_y1);
  triangleTemplate->m_shader.setVec("second", p_x2, p_y2);
  triangleTemplate->m_shader.setVec("third", p_x3, p_y3);

  float time = glfwGetTime() * 10;
  glm::mat4 trans = glm::mat4(1.0f);
  trans = glm::rotate(trans, glm::radians(time), glm::vec3(0.0f, 0.0f, 1.0f));
  triangleTemplate->m_shader.setMat("projection", trans);

  glm::mat4 view = glm::mat4(0.0f);

  view = glm::ortho(-x, x, -y, y, -x, y);
  /*
  view[0][0] = 200;
  view[1][1] = 200;
  view[2][2] = 1;
  view[3][3] = 1;
  */

  triangleTemplate->m_shader.setMat("view", view);

  triangleTemplate->m_shader.setVec("color", p_color.r, p_color.g, p_color.b);

  triangleTemplate->m_vbo.bind();
  triangleTemplate->m_vao.bind();

  glDrawArrays(GL_TRIANGLES, 0, 3);
}
} // namespace duffte