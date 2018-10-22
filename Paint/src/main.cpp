//#if 0

#define  GLM_ENABLE_EXPERIMENTAL
#include "../include/graphics.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform2.hpp>
#include <glm/gtc/type_ptr.hpp>

int main()
{

	mlg::RenderWindow myWindow(WIDTH, HEIGHT, "Paint");
	myWindow.create();

    mlg::KeyHandler::startTrack(myWindow);

    mlg::Shader shaderProg(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);


    mlg::Texture texture("../misc/windows.jpg");
    //mlg::Texture::bind(&texture);

	mlg::Camera2d camera;

    //shaderProg.use();
    //shaderProg.setInteger("ourTexture", 0);

    mlg::CircleShape circle;

	while (myWindow.isOpen())
	{
		myWindow.setBgColor(COLOR_WHITE, 1.f);
		mlg::Texture::bind(&texture);
        shaderProg.use();		
        shaderProg.setMat4("model", camera.getModelMat());
        myWindow.draw(texture);
		myWindow.display();
	}

	myWindow.close();
	return 0;
}

//#endif



#if 0

#include <glad/glad.h>
#include <include/graphics.h>
#include <iostream>

std::vector<mlg::Vector3f> g_vertices;
std::vector<unsigned> g_indexes;
unsigned VBO, VAO, EBO;
bool g_mouseClicked = false, g_mouseReleased = false;
double xpos = .0, ypos = .0;


mlg::Vector3f get_2d_ndc_coord(const float& positionX, const float& positionY)
{
	return mlg::Vector3f(static_cast<float>( (positionX - (WIDTH  / 2)) / (WIDTH  / 2)),
						 static_cast<float>(-(positionY - (HEIGHT / 2)) / (HEIGHT / 2)),
						 .0f);
}

void update(GLFWwindow* window)
{

	if (g_mouseClicked)
	{


// 		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
// 		glEnableVertexAttribArray(0);

		glfwGetCursorPos(window, &xpos, &ypos);

		g_indexes.push_back(g_vertices.size());
		g_vertices.push_back(get_2d_ndc_coord(static_cast<float>(xpos), static_cast<float>(ypos)));

	}
	if (g_mouseReleased)
	{
		g_indexes.push_back(0xFFFF);
	}


}

void mouseButtonCallback(GLFWwindow* window, int scancode, int action, int mods)
{
	g_mouseClicked = true;
	glfwGetCursorPos(window, &xpos, &ypos);
	if (scancode == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		g_mouseClicked  = true;
		g_mouseReleased = false;		
	}
	else if (action == GLFW_RELEASE)
	{
		g_mouseClicked  = false;
		g_mouseReleased = true;
	}
}

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", NULL, NULL);
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, mlg::framebuffer_size_callback);
	// glad: load all OpenGL function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	glfwSetMouseButtonCallback(window, mouseButtonCallback);
	// build and compile our shader program
	mlg::Shader shaderProg(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);

	float vertices[] = {
		 .2f, -.2f, .0f,
		 .3f,  .2f, .0f,
		-.3f, -.2f, .0f,
		 .6f, -.6f, .0f,
		-.5,  -.3f, .0f,
		-.2f, -.2f, .0f,
	};

	unsigned indexes[] = {
		0, 1, 2,  0xFFFF, 
		3, 4, 5,
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

 	glBindVertexArray(VAO);
  	glBindBuffer(GL_ARRAY_BUFFER, VBO);
// 
  	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
// 
 	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
 	glEnableVertexAttribArray(0);
// 
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	// render loop
	while (!glfwWindowShouldClose(window))
	{
		// render
		glClearColor(1.f, 1.f, 1.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);



		// draw our first triangle
		shaderProg.use();






		update(window);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, static_cast<int>(g_vertices.size() * sizeof(mlg::Vector3f)), g_vertices.data(), GL_DYNAMIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast<int>(g_indexes.size() * sizeof(unsigned)), g_indexes.data(), GL_DYNAMIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		glBindVertexArray(VAO);
		glEnable(GL_PRIMITIVE_RESTART);
		glPrimitiveRestartIndex(0xFFFF);
		glDrawElements(GL_LINE_STRIP, g_indexes.size(), GL_UNSIGNED_INT, reinterpret_cast<void*>(0));
		glDisable(GL_PRIMITIVE_RESTART);
		glBindVertexArray(0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glfwTerminate();
	return 0;
}

#endif
