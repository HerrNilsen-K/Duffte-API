#include <GL/glew.h>
#include "gameWindowHandler.hpp"
#include "../../util.hpp"
#include <iostream>

namespace duffte
{
    void gameWindow::init(int width, int height, std::string name)
    {
        m_window.setDimensions(width, height);
        m_window.createWindow(name);
        m_window.makeContextCurrent();

        glewInit();
        //Set user pointer to access "this" in "staticResizeCall"
        glfwSetWindowUserPointer(m_window.ID(), reinterpret_cast<void *>(this));

        glfwSetWindowSizeCallback(m_window.ID(), [](GLFWwindow *window, int width, int height) {
            gameWindow *gw = reinterpret_cast<gameWindow *>(glfwGetWindowUserPointer(window));
            if (gw)
                gw->resizeCall(width, height);
            else
            {
                ERROR_LOG("Error: gw in duffte::gameWindow::init() -> glfwSetWindowSizeCallback() == NULL");
            }
        });

        glfwSetKeyCallback(m_window.ID(), [](GLFWwindow *window, int key, int scancode, int action, int mods) {
            gameWindow *gw = reinterpret_cast<gameWindow *>(glfwGetWindowUserPointer(window));
            if (gw)
                gw->keyCall(key, scancode, action, mods);
            else
                ERROR_LOG("Error: gw in duffte::gameWindow::init() glfwSetKeyCallback() == NULL");
        });
    }

    void gameWindow::startEngine()
    {
        onStart();
        startRenderLoop();
        onExit();
    }

    duffte::key gameWindow::getCurrentKey()
    {
        return m_currentKey;
    }

    int gameWindow::getCurrentKeyMode()
    {
        return m_currentKeyMode;
    }

    bool gameWindow::startRenderLoop()
    {
        while (m_window.runs())
        {
            render();
        }
        return true;
    }

    void gameWindow::render()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        mainLoop();
        m_window.swapBuffers();
        m_window.pollEvents();
    }

    void gameWindow::resizeCall(int width, int height)
    {
        render();
        glViewport(0, 0, width, height);
    }

    void gameWindow::keyCall(int key, int scancode, int action, int mods)
    {
        m_currentKey = (duffte::key)key;
        m_currentKeyMode = action;
    }

} // namespace duffte