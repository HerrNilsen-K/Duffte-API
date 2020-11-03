#ifndef __GAMEWINDOWHANDLER_H__
#define __GAMEWINDOWHANDLER_H__

#include "mainWindowHandler.hpp"

class gameWindow
{
protected:
    Window windowOBJ;

private:
    //Creates the resize call for GLFW and forwards to "resizeCall(int, int)"
    static void staticResizeCall(GLFWwindow *window, int width, int height);
    void resizeCall(int width, int height);

public:
    void init(int width, int height, std::string name);

    bool startRenderLoop();
    //Calls the function, given by the constructor every 1/60 sec / every frame
    virtual void mainLoop() = 0;
};

#endif // __GAMEWINDOWHANDLER_H__