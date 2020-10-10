#ifndef __GAMEWINDOWHANDLER_H__
#define __GAMEWINDOWHANDLER_H__

#include "mainWindowHandler.h"

class gameWindow
{
private:
    Window windowOBJ;

    typedef void (*argPTR)();
    argPTR functionID;

public:
    //Stores a reference to a function that will be called in "startRendererLoop"
    gameWindow(argPTR arg, int width, int height);
    ~gameWindow();

    //Calls the function, given by the constructor every 1/60 sec / every frame
    bool startRenderLoop();
};

#endif // __GAMEWINDOWHANDLER_H__