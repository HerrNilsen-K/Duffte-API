#ifndef __GAMEWINDOWHANDLER_H__
#define __GAMEWINDOWHANDLER_H__

#include "mainWindowHandler.hpp"

namespace duffte
{
    class gameWindow
    {
    protected:
        Window windowOBJ;

    private:
        //Creates the resize call for GLFW and forwards to "resizeCall(int, int)"
        static void staticResizeCall(GLFWwindow *window, int width, int height);
        void resizeCall(int width, int height);

        //Calls mainLoop every 1/60 sec / every frame
        bool startRenderLoop();

    public:
        //Constructor alternative
        void init(int width, int height, std::string name);

        //Starts the loop of he window, must be called at the end of the constructor,
        //that derives gameWindow
        void startEngine();

        //Will becalled once on startup
        virtual void onStart() = 0;
        //Main loop that gets called every 1/60 sec / every frame
        virtual void mainLoop() = 0;
        //Will be called when the window is closed
        virtual void onExit() = 0;
    };
} // namespace duffte

#endif // __GAMEWINDOWHANDLER_H__