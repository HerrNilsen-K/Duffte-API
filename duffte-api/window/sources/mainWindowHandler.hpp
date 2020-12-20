#ifndef __MAINWINDOWHANDLER_H__
#define __MAINWINDOWHANDLER_H__

#define GLEW_STATIC       
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

namespace duffte
{
     struct windowSize
    {
        uint16_t x, y;
    };

    class Window
    {

    public:
        Window();
        ~Window();

        //Returns a pointer to GLFWwindow ID
        GLFWwindow *ID();

        //Sets the m_width and m_height of the window
        void setDimensions(int m_width, int m_height);
        //Sets the X and Y position of the window
        void setPosition(int m_posX, int m_posY);
        //Set the title of the window
        void setTitle(const std::string &title);

        //Creates and dissplays the window
        void createWindow();
        //Makes context to current
        void makeContextCurrent();

        //Changes the title
        void changeTitle(const std::string &title);

        //Get the size of the window
        windowSize getWindowSize() const;

        //Returns true as long as the window is opend
        bool runs();
        //Swaps buffers
        void swapBuffers();
        //Polls events
        void pollEvents();
    private:
        GLFWwindow *m_window;
        uint16_t m_width, m_height, m_posX, m_posY;
        std::string m_title;
    };
} // namespace duffte

#endif // __MAINWINDOWHANDLER_H__