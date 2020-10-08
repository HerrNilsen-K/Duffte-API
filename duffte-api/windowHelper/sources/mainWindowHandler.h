#ifndef __MAINWINDOWHANDLER_H__
#define __MAINWINDOWHANDLER_H__

#include <GLFW/glfw3.h>

class Window
{
private:
    GLFWwindow *windowID;
    int width, height, posX = 0, posY = 0;

public:
    Window();
    ~Window();

    //Sets the width and height of the window 
    void setDimensions(int width, int height);
    //Sets the X and Y position of the window
    void setPosition(int posX, int posY);
    //Creates and dissplays the window
    void createWindow(char *windowTitle);
};
#endif // __MAINWINDOWHANDLER_H__