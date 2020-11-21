#include "../duffte-api.hpp"
#include <iostream>

class game : public duffte::gameWindow
{
public:
    duffte::VBO vbo;
    duffte::VAO vao;
    duffte::SHADER shader;

    game(int argc, const char **argv)
    {
    }

    virtual void
    onStart()
    {
        std::cout << "Engine has started\n";
        duffte::vboCoords coords[] = {
            {{0, 1, 0},
             {0, 0}},

            {{1, -1, 0},
             {0, 0}},

            {{-1, -1, 0},
             {0, 0}}};

        const char *vertexShaderSource =
            "#version 330 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "layout (location = 1) in vec2 non; \n"
            "void main()\n"
            "{\n"
            "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
            "}\0";
        const char *fragmentShaderSource =
            "#version 330 core\n"
            "out vec4 FragColor;\n"
            "void main()\n"
            "{\n"
            "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
            "}\n\0";

        vbo.data(coords, sizeof(coords) / sizeof(*coords))
            .bind();
        vao.push(duffte::constant::vertSize, duffte::constant::coordStride, duffte::constant::vertOffset)
            .push(duffte::constant::texSize, duffte::constant::coordStride, duffte::constant::texOffset);
        shader.shaders(vertexShaderSource, fragmentShaderSource);
    }

    virtual void mainLoop()
    {
        duffte::renderer::rawRendering(vbo, vao, shader);
    }

    virtual void onExit()
    {
        std::cout << "Engine has been shutdown\n";
    }
};

int main(int argc, const char **argv)
{
    //Glew Doesn't initilize because there is no opengl context
    game *p_game = new class game(argc, argv);
    p_game->init(400, 400, "test");
    p_game->startEngine();
    delete p_game;
    //Render stuff in a render loop
    return 0;
}
