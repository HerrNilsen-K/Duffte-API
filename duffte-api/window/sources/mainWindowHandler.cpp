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

    void Window::createWindow(std::string windowTitle)
    {
        windowID = glfwCreateWindow(width, height, windowTitle.c_str(), 0, 0);
    }

    void Window::makeContextCurrent()
    {
        glfwMakeContextCurrent(windowID);
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