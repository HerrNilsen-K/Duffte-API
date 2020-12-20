#include "mainWindowHandler.hpp"
#include <GLFW/glfw3.h>
#include <string>

namespace duffte
{
    Window::Window() : m_posX(0), m_posY(0)
    {
        glfwInit();
    }

    Window::~Window()
    {
        glfwTerminate();
    }

    GLFWwindow *Window::ID()
    {
        return this->m_window;
    }

    void Window::setDimensions(int m_width, int m_height)
    {
        this->m_width = m_width;
        this->m_height = m_height;
    }

    void Window::setPosition(int m_posX, int m_posY)
    {
        this->m_posX = m_posX;
        this->m_posY = m_posY;
    }

    void Window::setTitle(const std::string &p_title)
    {
        this->m_title = p_title;
    }

    void Window::createWindow()
    {
        m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), 0, 0);
    }

    void Window::makeContextCurrent()
    {
        glfwMakeContextCurrent(m_window);
    }

    void Window::changeTitle(const std::string &p_title)
    {
        glfwSetWindowTitle(m_window, p_title.c_str());
    }

    windowSize Window::getWindowSize() const
    {
        glfwGetWindowSize(m_window, (int *)&m_width, (int *)&m_height);
        return {m_width, m_height};
    }

    bool Window::runs()
    {
        return !glfwWindowShouldClose(m_window);
    }

    void Window::swapBuffers()
    {
        glfwSwapBuffers(m_window);
    }

    void Window::pollEvents()
    {
        glfwPollEvents();
    }
} // namespace duffte