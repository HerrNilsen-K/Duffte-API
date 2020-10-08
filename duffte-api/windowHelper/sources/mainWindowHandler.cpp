#include "mainWindowHandler.h"
#include <iostream>

Window::Window()
{
    glfwInit();
}

Window::~Window()
{
    glfwTerminate();
}

void Window::setDimensions(int width, int height)
{
    this->width = width;
    this->height = height;
}

void Window::setPosition(int posX, int posY)
{
    this->posX = posX;
    this->posY = posY;
}

void Window::createWindow(std::string windowTitle) 
{
    windowID = glfwCreateWindow(width, height, windowTitle.c_str(), 0, 0);
}

void Window::makeContextCurrent(){
    glfwMakeContextCurrent(windowID);
}
