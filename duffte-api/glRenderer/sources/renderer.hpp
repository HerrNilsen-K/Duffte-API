#ifndef __RENDERER_HPP__
#define __RENDERER_HPP__

#include "VBO.hpp"
#include "VAO.hpp"
#include "SHADER.hpp"
#include "TEXTURE.hpp"

namespace duffte{
    class renderer{
        public:
        static void rawRendering(VBO &vbo, VAO &vao, SHADER &shader, TEXTURE &texture, unsigned int vertecies);
    };
}

#endif // __RENDERER_HPP__