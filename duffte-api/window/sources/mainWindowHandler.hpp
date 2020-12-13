#ifndef __MAINWINDOWHANDLER_H__
#define __MAINWINDOWHANDLER_H__

#define GLEW_STATIC       
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

namespace duffte
{
    class Window
    {

    public:
        Window();
        ~Window();

        //Returns a pointer to GLFWwindow ID
        GLFWwindow *ID();

        //Sets the width and height of the window
        void setDimensions(int width, int height);
        //Sets the X and Y position of the window
        void setPosition(int posX, int posY);
        //Set the title of the window
        void setTitle(const std::string &title);

        //Creates and dissplays the window
        void createWindow();
        //Makes context to current
        void makeContextCurrent();

        //Changes the title
        void changeTitle(const std::string &title);

        //Returns true as long as the window is opend
        bool runs();
        //Swaps buffers
        void swapBuffers();
        //Polls events
        void pollEvents();
    private:
        GLFWwindow *windowID;
        int width, height, posX, posY;
        std::string m_title;
    };
} // namespace duffte

#endif // __MAINWINDOWHANDLER_H__