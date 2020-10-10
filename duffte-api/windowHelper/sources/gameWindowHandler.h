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
    gameWindow(argPTR arg);
    ~gameWindow();
};

#endif // __GAMEWINDOWHANDLER_H__