#include "gameWindowHandler.h"
#include <iostream>

gameWindow::gameWindow()
{
    glfwSetWindowUserPointer(windowOBJ.ID(), reinterpret_cast<void *>(this));

    functionID = []() {
        std::cout << "Alternative\n";
    };
}

gameWindow::gameWindow(argPTR arg, int width, int height, std::string name)
{
    functionID = arg;
    windowOBJ.setDimensions(width, height);
    windowOBJ.createWindow(name);
    windowOBJ.makeContextCurrent();
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
    //gw->windowOBJ.setDimensions(width, height);
    if (gw)
        gw->resizeCall(width, height);
    else
    {
        std::cout << "gw == false" << std::endl;
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


void gameWindow::operator=(const gameWindow &gw) 
{  
    this->functionID = gw.functionID;
    this->windowOBJ = gw.windowOBJ;
}
