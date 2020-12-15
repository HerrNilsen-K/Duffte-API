#include "../duffte-api.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

void MessageCallback(GLenum source,
                     GLenum type,
                     GLuint id,
                     GLenum severity,
                     GLsizei length,
                     const GLchar *message,
                     const void *userParam)
{

    std::cout << "---------------------opengl-callback-start------------" << std::endl;
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
    std::cout << "---------------------opengl-callback-end--------------" << std::endl
              << std::endl;
}

class game : public duffte::gameWindow
{
public:
    game(int argc, const char **argv)
    {
    }

    virtual void
    onStart()
    {
        glEnable(GL_DEBUG_OUTPUT);
        glDebugMessageCallback(MessageCallback, 0);

        std::cout << "Engine has started\n";
        glfwSwapInterval(1);
    }

    double lastTime = glfwGetTime();
    int nbFrames = 0;

    virtual void mainLoop()
    {
        static double i = 0, j = -0.5;
        duffte::triangle2D(-1, 1, 0, 0, -1, -1);
        duffte::triangle2D(i, 0.5, i + .5, -0.5, j, -0.5, {.5, .2, .1});
        i += 0.005;
        j += 0.005;
        if (j >= 1)
        {
            i = -1.5;
            j = -2;
        }

        double currentTime = glfwGetTime();
        nbFrames++;
        if (currentTime - lastTime >= 1)
        { // If last prinf() was more than 1 sec ago
            // printf and reset timer
            std::string title = std::to_string(nbFrames);
            duffte::gameWindow::m_window.changeTitle(title);
            nbFrames = 0;
            lastTime += 1.0;
        }
    }

    virtual void onExit()
    {
        std::cout << "Engine has been shutdown\n";
    }
};

int main(int argc, const char **argv)
{
    game *p_game = new class game(argc, argv);
    p_game->init(400, 400, "Hello World", duffte::flags::GRAPHICS);
    p_game->startEngine();
    delete p_game;
    return 0;
}
