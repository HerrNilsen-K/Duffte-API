#include "../duffte-api.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

void MessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity,
                     GLsizei length, const GLchar *message,
                     const void *userParam)
{

  std::cout << "---------------------opengl-callback-start------------"
            << std::endl;
  std::cout << "message: " << message << std::endl;
  std::cout << "type: ";
  switch (type)
  {
  case GL_DEBUG_TYPE_ERROR:
    std::cout << "ERROR";
    break;
  case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
    std::cout << "DEPRECATED_BEHAVIOR";
    break;
  case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
    std::cout << "UNDEFINED_BEHAVIOR";
    break;
  case GL_DEBUG_TYPE_PORTABILITY:
    std::cout << "PORTABILITY";
    break;
  case GL_DEBUG_TYPE_PERFORMANCE:
    std::cout << "PERFORMANCE";
    break;
  case GL_DEBUG_TYPE_OTHER:
    std::cout << "OTHER";
    break;
  }
  std::cout << std::endl;

  std::cout << "id: " << id << std::endl;
  std::cout << "severity: ";
  switch (severity)
  {
  case GL_DEBUG_SEVERITY_LOW:
    std::cout << "LOW";
    break;
  case GL_DEBUG_SEVERITY_MEDIUM:
    std::cout << "MEDIUM";
    break;
  case GL_DEBUG_SEVERITY_HIGH:
    std::cout << "HIGH";
    break;
  }
  std::cout << std::endl;
  std::cout << "---------------------opengl-callback-end--------------"
            << std::endl
            << std::endl;
}

class game : public duffte::gameWindow
{
public:
  game(int argc, const char **argv) {}

  void onStart() override
  {
    //glEnable(GL_DEBUG_OUTPUT);
    //glDebugMessageCallback(MessageCallback, 0);

    std::cout << "Engine has started\n";
    glfwSwapInterval(0);
    /*glfwWindowHint(GLFW_SAMPLES, 4);
    glEnable(GL_MULTISAMPLE);*/
    glEnable(GL_DEPTH_TEST);
  }

  double lastTime = glfwGetTime();
  int nbFrames = 0;

  void mainLoop(double time) override
  {
    static double i = 0, j = -200;
    duffte::triangle2D(-400, 400, 0, 0, -400, -400, getWindowSize().x, getWindowSize().y);
    duffte::triangle2D(i, 200, i + 200, -200, j, -200, getWindowSize().x, getWindowSize().y, {.5, .2, .1});
    /*i += 4;
    j += 4;
    if (j >= getWindowSize().x)
    {
      i = -getWindowSize().x - 400;
      j = -getWindowSize().x - 800;
    }*/
    double t = 1 / time;
    changeTitle(t);
  }

  void onExit() override { std::cout << "Engine has been shutdown\n"; }
};

int main(int argc, const char **argv)
{
  game *p_game = new class game(argc, argv);
  p_game->init(400, 400, "Hello World", duffte::flags::GRAPHICS | duffte::flags::DRAW_3D);
  p_game->startEngine();
  delete p_game;
  return 0;
}
