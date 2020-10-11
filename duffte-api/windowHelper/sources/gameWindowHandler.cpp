#include "gameWindowHandler.h"

gameWindow::gameWindow(argPTR arg, int width, int height, std::string name)
{
    functionID = arg;
    glfwSetFramebufferSizeCallback(windowOBJ.windowID(), resizeCall);
    windowOBJ.setDimensions(width, height);
    windowOBJ.createWindow(name);
    windowOBJ.makeContextCurrent();
}

gameWindow::~gameWindow()
{
}

bool gameWindow::startRenderLoop()
{
    while (windowOBJ.runs())
    {
        //glClear(GL_COLOR_BUFFER_BIT);
        functionID();
        windowOBJ.swapBuffers();
        windowOBJ.pollEvents();
    }
    return true;
}
void gameWindow::resizeCall(GLFWwindow* window, int width, int height) 
{
    glViewport(0, 0, width, height);
}
