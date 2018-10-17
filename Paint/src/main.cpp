//#if 0
#define GLM_ENABLE_EXPERIMENTAL
#include "../include/graphics.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform2.hpp>
#include <glm/gtc/type_ptr.hpp>

mlg::Camera2d camera(glm::vec3(0.0f, 0.0f, 3.0f));
void startMouseScrollTrack(GLFWwindow* window, double xOffset, double yOffset);

int main()
{

	mlg::RenderWindow myWindow(WIDTH, HEIGHT, "Paint");
	myWindow.create();

    mlg::KeyHandler::startKeysTrack(myWindow);
    glfwSetScrollCallback(myWindow.m_window, startMouseScrollTrack);

    mlg::Shader shaderProg(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);
    //mlg::Shader shaderProg("../../src/vert_shader.vert", "../../src/frag_shader.frag");

    mlg::Texture texture;
    mlg::Texture::bind(&texture);
    texture.generate();

    shaderProg.use();
    shaderProg.setInteger("ourTexture", 0);

    mlg::CircleShape circle;

	while (myWindow.isOpen())
	{
        //myWindow.setBgColor(COLOR_WHITE, 1.f);
        shaderProg.use();

        // pass projection matrix to shader
        glm::mat4 projection = glm::perspective(glm::radians(camera.getZoom()),
                static_cast<float>(WIDTH) / static_cast<float>(HEIGHT),
                0.1f,
                10000.f);
        shaderProg.setMat4("projecton", projection);
        // camera view transformation
        glm::mat4 view = camera.getViewMatrix();
        shaderProg.setMat4("view", view);

        glm::mat4 model = glm::translate(model, glm::vec3(0.f, 0.f, 0.f));
        model = glm::rotate(model, glm::radians(0.f), glm::vec3(1.0f, 0.3f, 0.5f));
        shaderProg.setMat4("model", model);

        myWindow.draw(texture, circle);
		myWindow.display();
	}

	myWindow.close();
	return 0;
}

void startMouseScrollTrack(GLFWwindow* window, double xOffset, double yOffset)
{
    camera.mouseScrollCallback(static_cast<float>(yOffset));
}

//#endif
