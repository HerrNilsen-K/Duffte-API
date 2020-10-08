#include "mainWindowHandler.h"
#include <iostream>

Window::Window()
{
    glfwInit();
}

Window::~Window()
{
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

void Window::createWindow(char *windowTitle) 
{
    windowID = glfwCreateWindow(width, height, windowTitle, 0, 0);
}
