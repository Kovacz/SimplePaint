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

#if 0

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <../include/graphics.h>
#include <vector>
#include <cmath>

// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);


std::vector<mlg::Vector3f> vertices
//=
//{
//    mlg::Vector3f(-0.3f, 0.2f, 0.f),
//    mlg::Vector3f(0.3f, 0.2f, 0.f),
//}
;

void DrawCircle(float cx, float cy, float r, int num_segments)
{
    for (int ii = 0; ii <= num_segments; ++ii)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 

		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 

		vertices.push_back(mlg::Vector3f(x + cx, y + cy, 0.f));
	}
}

// The MAIN function, from here we start the application and run the game loop
int main()
{
	glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));
	// Define the viewport dimensions
    glViewport(0, 0, WIDTH, 800);
    mlg::Shader shaderProgram("../../src/vert_shader.vert", "../../src/frag_shader.frag");
	// Set up vertex data (and buffer(s)) and attribute pointers
// 	GLfloat vertices[] = {
// 		 // Positions         // Colors           // Texture Coords
// 		 -1.0f,  1.0f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // Top Right
// 		  1.0f, 1.0f, 0.0f,    0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // Bottom Right
// 		  1.0f, -1.0f, 0.0f,    0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
// 		 -1.0f,  -1.0f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // Top Left 
// 	};
// 	GLuint indices[] = {  // Note that we start from 0!
// 		0, 1, 3, // First Triangle
// 		1, 2, 3  // Second Triangle
// 	};

    DrawCircle(0.3f, 0.2f, 0.2f, 40);

	GLuint VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(mlg::Vertex3) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

// 	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
// 	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, 3 * sizeof(float), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	// Color attribute
// 	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
// 	glEnableVertexAttribArray(1);
// 	// TexCoord attribute
// 	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
// 	glEnableVertexAttribArray(2);

    //glBindVertexArray(0); // Unbind VAO





	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(1.f, 1.f, 1.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);
		shaderProgram.use();



        //glBindVertexArray(VAO);
        glDrawArrays(GL_LINE_LOOP, 0, vertices.size());
        //glBindVertexArray(0);

		// Swap the screen buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	// Properly de-allocate all resources once they've outlived their purpose
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
	return 0;
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

#endif
