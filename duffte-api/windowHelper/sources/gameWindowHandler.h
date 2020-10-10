#ifndef __GAMEWINDOWHANDLER_H__
#define __GAMEWINDOWHANDLER_H__

#include "mainWindowHandler.h"

class gameWindow
{
private:
    Window windowOBJ;
public:
    gameWindow(void (*args)());
    ~gameWindow();
};

#endif // __GAMEWINDOWHANDLER_H__