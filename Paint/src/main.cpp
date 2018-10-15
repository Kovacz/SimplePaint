#if 0

#include <include/graphics.h>

int main()
{

	mlg::RenderWindow myWindow(WIDTH, HEIGHT, "Paint");
	myWindow.create();

	mlg::KeyHandler::startBoardTrack(myWindow);
	mlg::KeyHandler::startMouseTrack(myWindow);

	//mlg::Shader shaderProg1(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);
	mlg::Shader shaderProg("../src/shaders/texture_vert_shader.vert", "../src/shaders/texture_frag_shader.frag");

	mlg::Texture texture;
	mlg::Texture::bind(&texture);
	texture.setTexParametri();
	texture.generate();

	while (myWindow.isOpen())
	{
		//myWindow.setBgColor(COLOR_WHITE, 1.f);
		shaderProg.use();
		
		myWindow.draw(texture);
		myWindow.display();
	}

	myWindow.close();
	return 0;
}

#endif

//#if 0

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <include/graphics.h>
#include <vector>

// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);


std::vector<mlg::Vector3f> vertices;

void DrawCircle(float cx, float cy, float r, int num_segments)
{
	for (int ii = 0; ii < num_segments; ii++)
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
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));
	// Define the viewport dimensions
	glViewport(0, 0, WIDTH, HEIGHT);
	mlg::Shader shaderProgram("../src/shaders/texture_vert_shader.vert", "../src/shaders/texture_frag_shader.frag");
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
	DrawCircle(-0.5f, 0.f, 0.1f, 10);


	GLuint VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(mlg::Vertex3), &vertices[0], GL_STATIC_DRAW);

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




	// Load and create a texture 
	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture); // All upcoming GL_TEXTURE_2D operations now have effect on this texture object
										   // Set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// Load image, create texture and generate mipmaps

	unsigned char* image = new unsigned char[WIDTH * HEIGHT * 4];
	for (size_t i = 0; i < WIDTH * HEIGHT * 4; ++i)
		image[i] = 255;


	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, WIDTH, HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.





	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(1.f, 1.f, 1.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);
		shaderProgram.use();


		glDrawArrays(GL_LINE_LOOP, 0, vertices.size());
// 		glBindVertexArray(VAO);
// 		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
// 		glBindVertexArray(0);

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

//#endif