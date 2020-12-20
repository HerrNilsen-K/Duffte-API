#ifndef __GAMEWINDOWHANDLER_H__
#define __GAMEWINDOWHANDLER_H__

#include "mainWindowHandler.hpp"
#include "../../glRenderer/sources/constants.hpp"

namespace duffte
{
    class gameWindow
    {

    public:
        //Arguments for window creation
        void init(int width, int height, std::string name, int flags = 0);

        //Starts the loop of he window, must be called at the end of the constructor,
        //that derives gameWindow
        void startEngine();

        //Will becalled once on startup
        virtual void onStart() = 0;
        //Main loop that gets called every 1/60 sec / every frame
        virtual void mainLoop() = 0;
        //Will be called when the window is closed
        virtual void onExit() = 0;

        virtual ~gameWindow() {}

        //Window manipulators
        void changeTitle(const std::string &title);
        void changeTitle(int &title);
        void changeTitle(float &title);

    public:
        windowSize getWindowSize();

        duffte::key getCurrentKey();
        int getCurrentKeyMode();
        bool keyIsHeld();

    private:
        Window m_window;

        key m_currentKey;
        int m_currentKeyMode;
        bool m_hold;

        uint64_t m_flags;

    private:
        //"resizeCall" gets calledwhen the window is being resized, and calls "mainLoopContainer"
        void resizeCall(int width, int height);
        void reposCall(int x, int y);

        //Callback to recieve the currently pressed key
        void keyCall(int key, int scancode, int action, int mods);
        //Calls mainLoop every 1/60 sec / every frame
        bool startRenderLoop();

        //Calls all rendering functions
        void render();

        void terminate();
    };
} // namespace duffte

#endif // __GAMEWINDOWHANDLER_H__