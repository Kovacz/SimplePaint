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

    mlg::KeyHandler::startKeysTrack(myWindow);

    mlg::Shader shaderProg(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);


    mlg::Texture texture("../../misc/windows.jpg");
    //mlg::Texture::bind(&texture);

	mlg::Camera2d camera;

    shaderProg.use();
    shaderProg.setInteger("ourTexture", 0);

    mlg::CircleShape circle;

	while (myWindow.isOpen())
	{

        myWindow.setBgColor(COLOR_WHITE, 1.f);
		mlg::Texture::bind(&texture);
        shaderProg.use();
        shaderProg.setMat4("model", camera.getModelMat());
        myWindow.draw(texture, circle);
		myWindow.display();
	}

	myWindow.close();
	return 0;
}


//#endif
