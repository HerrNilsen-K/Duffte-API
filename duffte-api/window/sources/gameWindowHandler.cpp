#include "gameWindowHandler.hpp"
#include "../../util.hpp"
#include <iostream>

gameWindow::gameWindow(argPTR arg, int width, int height, std::string name)
: functionID(arg)
{
    windowOBJ.setDimensions(width, height);
    windowOBJ.createWindow(name);
    windowOBJ.makeContextCurrent();
    //Set user pointer to access "this" in "staticResizeCall"
    glfwSetWindowUserPointer(windowOBJ.ID(), reinterpret_cast<void *>(this));
    glfwSetWindowSizeCallback(windowOBJ.ID(), staticResizeCall);
}

gameWindow::~gameWindow()
{
}

bool gameWindow::startRenderLoop()
{
    while (windowOBJ.runs())
    {
        renderContainer();
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

    renderContainer();
    glViewport(0, 0, width, height);
}

void gameWindow::renderContainer()
{
    glClear(GL_COLOR_BUFFER_BIT);
    functionID();
    windowOBJ.swapBuffers();
    windowOBJ.pollEvents();
}
