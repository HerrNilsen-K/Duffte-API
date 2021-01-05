#include "triangle.hpp"
#include "../../util.hpp"
#include "triangleCreation.hpp"
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

duffte::trinagleCreation *triangleTemplate;

namespace duffte
{
  void triangle2D(float p_x1, float p_y1, float p_x2, float p_y2, float p_x3,
                  float p_y3, float x, float y, __colorContainer p_color)
  {

    triangleTemplate->m_shader.use();
    triangleTemplate->m_shader.setVec("first", p_x1, p_y1);
    triangleTemplate->m_shader.setVec("second", p_x2, p_y2);
    triangleTemplate->m_shader.setVec("third", p_x3, p_y3);

    float time = glfwGetTime() * 10;
    const float radius = 10.0f;
    float camX = sin(glfwGetTime()) * radius;
    float camZ = cos(glfwGetTime()) * radius;
    glm::mat4 view;
    view = glm::lookAt(glm::vec3(0.0, 0.0, 1.0),
                       glm::vec3(0.0, 0.0, 0.0),
                       glm::vec3(0.0, 1.0, 0.0));
    //trans = glm::rotate(trans, glm::radians(time), glm::vec3(0.f, 0.f, 1.f));
    //trans = glm::scale(trans, glm::vec3(1.f, 1.5f, 1.f));
    triangleTemplate->m_shader.setMat("projection", view);

    glm::mat4 orth = glm::mat4(0.0f);
    orth = glm::ortho(-x, x, -y, y, -x, y);
    /*
  view[0][0] = 200;
  view[1][1] = 200;
  view[2][2] = 1;
  view[3][3] = 1;
  */

    triangleTemplate->m_shader.setMat("view", orth);

    triangleTemplate->m_shader.setVec("color", p_color.r, p_color.g, p_color.b);

    triangleTemplate->m_vbo.bind();
    triangleTemplate->m_vao.bind();

    glDrawArrays(GL_TRIANGLES, 0, 3);
  }
} // namespace duffte