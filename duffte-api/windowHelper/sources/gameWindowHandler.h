#ifndef __GAMEWINDOWHANDLER_H__
#define __GAMEWINDOWHANDLER_H__

#include "mainWindowHandler.h"

class gameWindow
{
private:

    typedef void (*argPTR)();
    argPTR functionID;

private:
    //Creates the resize call
    static void staticResizeCall(GLFWwindow *window, int width, int height);
    void resizeCall(int width, int height);

    //Calls the rendering function
    void renderContainer();

public:
    Window windowOBJ;
    //Stores a reference to a function that will be called in "startRendererLoop"
    gameWindow();
    gameWindow(argPTR arg, int width, int height, std::string);
    ~gameWindow();

    //Calls the function, given by the constructor every 1/60 sec / every frame
    bool startRenderLoop();

    void operator=(const gameWindow &gw);
};

#endif // __GAMEWINDOWHANDLER_H__