#include "mainWindowHandler.hpp"
#include <GLFW/glfw3.h>
#include <string>

namespace duffte
{
    Window::Window() : posX(0), posY(0)
    {
        glfwInit();
    }

    Window::~Window()
    {
        glfwTerminate();
    }

    GLFWwindow *Window::ID()
    {
        return this->windowID;
    }

    void Window::setDimensions(int width, int height)
    {
        this->width = width;
        this->height = height;
    }

    void Window::setPosition(int posX, int posY)
    {
        this->posX = posX;
        this->posY = posY;
    }

    void Window::setTitle(const std::string &p_title)
    {
        this->m_title = p_title;
    }

    void Window::createWindow()
    {
        windowID = glfwCreateWindow(width, height, m_title.c_str(), 0, 0);
    }

    void Window::makeContextCurrent()
    {
        glfwMakeContextCurrent(windowID);
    }

    void Window::changeTitle(const std::string &p_title)
    {
        glfwSetWindowTitle(windowID, p_title.c_str());
    }

    bool Window::runs()
    {
        return !glfwWindowShouldClose(windowID);
    }

    void Window::swapBuffers()
    {
        glfwSwapBuffers(windowID);
    }

    void Window::pollEvents()
    {
        glfwPollEvents();
    }
} // namespace duffte