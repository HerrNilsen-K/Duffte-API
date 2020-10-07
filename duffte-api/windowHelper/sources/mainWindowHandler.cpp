#include "mainWindowHandler.h"
#include <iostream>

void Window::setDimensions(int width, int height) 
{
    this->width = width;
    this->height = height;
}

Window::Window() 
{
   glfwInit();
}

Window::~Window() 
{
    
}
