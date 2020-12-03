#include "../duffte-api.hpp"
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>
#include <iostream>
#include <cmath>

class game : public duffte::gameWindow
{
public:
    duffte::VBO vbo;
    duffte::VAO vao;
    duffte::SHADER shader;
    duffte::TEXTURE texture;

    game(int argc, const char **argv)
    {
    }

    virtual void
    onStart()
    {
        for (int i = 0; i < 255; i++)
        {
        }

        std::cout << "Engine has started\n";
        duffte::vboCoords coords[] = {
            {{-1, -1, 1},
             {0, 0}},
            {{-1, 1, 1},
             {0, 1}},
            {{1, 1, 1},
             {1, 1}},
            {{1, 1, 1},
             {1, 1}},
            {{1, -1, 1},
             {1, 0}},
            {{-1, -1, 1},
             {0, 0}},

            {{-1, -1, 1},
             {0, 1}},
            {{-1, 1, 1},
             {1, 1}},
            {{-1, -1, -1},
             {0, 0}},
            {{-1, 1, 1},
             {1, 1}},
            {{-1, 1, -1},
             {1, 0}},
            {{-1, -1, -1},
             {0, 0}},

            {{-1, -1, -1},
             {0, 0}},
            {{-1, 1, -1},
             {0, 1}},
            {{1, 1, -1},
             {1, 1}},
            {{1, 1, -1},
             {1, 1}},
            {{1, -1, -1},
             {1, 0}},
            {{-1, -1, -1},
             {0, 0}},

            {{1, -1, 1},
             {0, 1}},
            {{1, 1, 1},
             {1, 1}},
            {{1, -1, -1},
             {0, 0}},
            {{1, 1, 1},
             {1, 1}},
            {{1, 1, -1},
             {1, 0}},
            {{1, -1, -1},
             {0, 0}},

            {{-1, 1, 1},
             {0, 1}},
            {{-1, 1, -1},
             {0, 0}},
            {{1, 1, 1},
             {1, 1}},
            {{1, 1, -1},
             {1, 0}},
            {{-1, 1, -1},
             {0, 0}},
            {{1, 1, 1},
             {1, 1}},

            {{-1, -1, 1},
             {0, 1}},
            {{-1, -1, -1},
             {0, 0}},
            {{1, -1, 1},
             {1, 1}},
            {{1, -1, -1},
             {1, 0}},
            {{-1, -1, -1},
             {0, 0}},
            {{1, -1, 1},
             {1, 1}}};

        const char *vertexShaderSource =
            "#version 330 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "layout (location = 1) in vec2 inTexPos;\n"
            "out vec2 aTexPos;\n"
            "uniform mat4 matrix;\n"
            "void main()\n"
            "{\n"
            "aTexPos = inTexPos;\n"
            "   gl_Position = vec4(aPos, 1.0) * matrix;\n"
            "}\0";
        const char *fragmentShaderSource =
            "#version 330 core\n"
            "out vec4 FragColor;\n"
            "in vec2 aTexPos;\n"
            "uniform sampler2D tex;\n"
            "void main()\n"
            "{\n"
            "   FragColor = texture(tex, aTexPos);\n"
            "}\n\0";

        vbo.data(coords, sizeof(coords) / sizeof(*coords))
            .bind();
        vao.push(duffte::constant::vertSize, duffte::constant::coordStride, duffte::constant::vertOffset);
        vao.push(duffte::constant::texSize, duffte::constant::coordStride, duffte::constant::texOffset);
        shader.shaders(vertexShaderSource, fragmentShaderSource);
        texture.path("panda.jpg");
        glEnable(GL_DEPTH_TEST);
    }

    virtual void mainLoop()
    {
        glm::mat4 rot = glm::mat4(1.0f);
        rot = glm::rotate(rot, glm::radians((float)glfwGetTime()) * 50, glm::vec3(0.0f, 1.0f, 0.0f));
        rot = glm::rotate(rot, glm::radians((float)glfwGetTime()) * 50, glm::vec3(0.0f, 1.0f, 1.0f));
        float angle = 20.0f * float(1);
        rot = glm::rotate(rot, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
        glm::mat4 trans = glm::mat4(1.0f);
        //trans = glm::translate(trans, glm::vec3(1.5f, 0.0f, 0.0f));
        float orth = 3.0f;

        glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
        glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);

        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));

        glm::vec3 cameraUP = glm::cross(cameraDirection, cameraRight);
        glm::mat4 proj;

        if (duffte::gameWindow::getCurrentKey() == duffte::key::E && duffte::gameWindow::getCurrentKeyMode() == GLFW_PRESS)
        {
            proj = glm::ortho(-orth, orth, -orth, orth, -orth, orth);
        }
        else
        {
            orth = 4.0f;
            proj = glm::ortho(-orth, orth, -orth, orth, -orth, orth);
        }

        const float radius = 10.0f;
        float camX = sin(glfwGetTime()) * radius;
        float camZ = cos(glfwGetTime()) * radius;
        glm::mat4 view;
        view = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));

        shader.setMat("matrix", rot * proj * trans);
        duffte::renderer::rawRendering(vbo, vao, shader, texture, 36);
        glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    }

    virtual void onExit()
    {
        std::cout << "Engine has been shutdown\n";
    }
};

int main(int argc, const char **argv)
{
    game *p_game = new class game(argc, argv);
    p_game->init(400, 400, "Hello World");
    p_game->startEngine();
    delete p_game;
    return 0;
}
