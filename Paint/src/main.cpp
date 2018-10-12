#include "../include/vertex.h"
#include "../include/shader.h"
#include "../include/graphics.h"
#include "../include/vertexbuffer.h"


const static int WIDTH  = 800;
const static int HEIGHT = 600;
const static std::string VERT = "../../src/vert_shader.vert";
const static std::string FRAG = "../../src/frag_shader.frag";


int main()
{
    mlg::RenderWindow myWindow(WIDTH, HEIGHT, "Paint");
    myWindow.create();

    mlg::Shader shaderProg(VERT, FRAG);

    mlg::Vertex vertices[3];
    vertices[0].position = mlg::Vector2f(-0.5f, -0.5f);
    vertices[1].position = mlg::Vector2f(0.5f, -0.5f);
    vertices[2].position = mlg::Vector2f(0.0f,  0.5f);


    while(myWindow.isOpen())
    {
        myWindow.setBgColor(1.f, 1.f, 1.f, 1.f);
        shaderProg.use();
        myWindow.draw(vertices);
        myWindow.display();
    }

    myWindow.close();
    return 0;
}

