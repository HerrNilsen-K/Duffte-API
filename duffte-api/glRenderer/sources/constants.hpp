#ifndef __CONSTANTS_HPP__
#define __CONSTANTS_HPP__
#include "VBOHelper.hpp"

namespace duffte
{
    //Temorary constants for the openGL pipeline creation
    enum constant
    {
        vertSize = sizeof(duffte::vertPos) / sizeof(duffte::vertPos::x),
        texSize = sizeof(duffte::texPos) / sizeof(duffte::texPos::x),
        vertOffset = 0,
        texOffset = sizeof(duffte::vertPos),
        coordStride = sizeof(duffte::vboCoords)
    };

//Value of all keyboard keys
    enum key
    {
        A = GLFW_KEY_A,
        B = GLFW_KEY_B,
        C = GLFW_KEY_C,
        D = GLFW_KEY_D,
        E = GLFW_KEY_E,
        F = GLFW_KEY_F,
        G = GLFW_KEY_G,
        H = GLFW_KEY_H,
        I = GLFW_KEY_I,
        J = GLFW_KEY_J,
        K = GLFW_KEY_K,
        L = GLFW_KEY_L,
        M = GLFW_KEY_M,
        N = GLFW_KEY_N,
        O = GLFW_KEY_O,
        P = GLFW_KEY_P,
        Q = GLFW_KEY_Q,
        R = GLFW_KEY_R,
        S = GLFW_KEY_S,
        T = GLFW_KEY_T,
        U = GLFW_KEY_U,
        V = GLFW_KEY_V,
        W = GLFW_KEY_W,
        X = GLFW_KEY_X,
        Y = GLFW_KEY_Y,
        Z = GLFW_KEY_Z
    };
} //namespace duffte

#endif // __CONSTANTS_H__