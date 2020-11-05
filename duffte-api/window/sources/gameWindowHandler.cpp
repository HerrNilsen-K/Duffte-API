#include <GL/glew.h>
#include "gameWindowHandler.hpp"
#include "../../util.hpp"
#include <iostream>

namespace duffte
{
    void gameWindow::init(int width, int height, std::string name)
    {
        windowOBJ.setDimensions(width, height);
        windowOBJ.createWindow(name);
        windowOBJ.makeContextCurrent();
        //Set user pointer to access "this" in "staticResizeCall"
        glfwSetWindowUserPointer(windowOBJ.ID(), reinterpret_cast<void *>(this));
        glfwSetWindowSizeCallback(windowOBJ.ID(), staticResizeCall);
        glewInit();
    }

    void gameWindow::startEngine()
    {
        onStart();
        startRenderLoop();
        onExit();
    }

    bool gameWindow::startRenderLoop()
    {
        while (windowOBJ.runs())
        {
            glClear(GL_COLOR_BUFFER_BIT);
            mainLoop();
            windowOBJ.swapBuffers();
            windowOBJ.pollEvents();
        }
        return true;
    }

    void gameWindow::staticResizeCall(GLFWwindow *window, int width, int height)
    {
        gameWindow *gw = reinterpret_cast<gameWindow *>(glfwGetWindowUserPointer(window));
        if (gw)
            gw->resizeCall(width, height);
        else
        {
            ERROR_LOG("Error: gw in staticResizeCall == 0");
        }
    }

    void gameWindow::resizeCall(int width, int height)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        mainLoop();
        windowOBJ.swapBuffers();
        windowOBJ.pollEvents();
        glViewport(0, 0, width, height);
    }

} // namespace duffte