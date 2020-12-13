#ifndef __TRIANGLECREATION_HPP__
#define __TRIANGLECREATION_HPP__

#include "../../glRenderer/glRenderer.hpp"

namespace duffte{
    class trinagleCreation{
        public:
        vboImpl m_vbo;
        vaoImpl m_vao;
        shaderImpl m_shader;

        public:
        trinagleCreation();
    };
}

#endif //__TRIANGLECREATION_HPP__