#ifndef __MAINWINDOWHANDLER_H__
#define __MAINWINDOWHANDLER_H__

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

namespace duffte
{
    class Window
    {
    private:
        GLFWwindow *windowID;
        int width, height, posX, posY;

    public:
        Window();
        ~Window();

        //Returns a pointer to GLFWwindow ID
        GLFWwindow *ID();

        //Sets the width and height of the window
        void setDimensions(int width, int height);
        //Sets the X and Y position of the window
        void setPosition(int posX, int posY);

        //Creates and dissplays the window
        void createWindow(std::string windowTitle);
        //Makes context to current
        void makeContextCurrent();

        //Returns true as long as the window is opend
        bool runs();
        //Swaps buffers
        void swapBuffers();
        //Polls events
        void pollEvents();
    };
} // namespace duffte

#endif // __MAINWINDOWHANDLER_H__