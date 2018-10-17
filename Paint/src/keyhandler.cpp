#include "../include/keyhandler.h"
#include "../include/renderwindow.h"
#include "../include/camera2d.h"
#include <iostream>

namespace mlg
{
// Vector2f KeyHandler::sMouseCoordsPress(0.f, 0.f);
// Vector2f KeyHandler::sMouseCoordsRelease(0.f, 0.f);
bool KeyHandler::mouseClicked = false;

void KeyHandler::keyboardCallback(GLFWwindow* window
		, int key
		, int scancode
		, int action
		, int mods
		)
{
	if (key == GLFW_KEY_L && action == GLFW_PRESS)
	{
		g_vertices.clear();
		singleDrawMode.setMode(DrawMode::LINES_MODE);
	}
	else if (key == GLFW_KEY_S && action == GLFW_PRESS)
	{
		g_vertices.clear();
		singleDrawMode.setMode(DrawMode::LINES_STRIP_MODE);
	}
	else if (key == GLFW_KEY_B && action == GLFW_PRESS)
	{
		g_vertices.clear();
		singleDrawMode.setMode(DrawMode::BRUSH_MODE);
	}
	else if (key == GLFW_KEY_C && action == GLFW_PRESS)
	{
		g_vertices.clear();
		singleDrawMode.setMode(DrawMode::CIRCLE_MODE);
	}
    else if (key == GLFW_KEY_N && action == GLFW_PRESS)
    {
        g_vertices.clear();
        singleDrawMode.setMode(DrawMode::LOAD_BG_MODE);
    }
}

void KeyHandler::mouseButtonCallback(GLFWwindow* window
		, int scancode
		, int action
		, int mods
		)
{
	double		xpos  = 0, ypos   = 0;
	int			width = 0, height = 0;
	glfwGetCursorPos(window, &xpos, &ypos);
	glfwGetWindowSize(window, &width, &height);
	if (scancode == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		mouseClicked = true;
        if (singleDrawMode.getModeState() != DrawMode::BRUSH_MODE)
        {
            g_X1 = static_cast<float>( (xpos - (width  / 2)) / (width  / 2));
            g_Y1 = static_cast<float>(-(ypos - (height / 2)) / (height / 2));
        }
    }
    else if (action == GLFW_RELEASE)
	{
		mouseClicked = false;
        if (singleDrawMode.getModeState() != DrawMode::LINES_MODE
         || singleDrawMode.getModeState() != DrawMode::CIRCLE_MODE)
		{
			singleDrawMode.setDrawFlag(true);

            g_X2 = static_cast<float>((xpos - (width / 2)) / (width / 2));
			g_Y2 = static_cast<float>(-(ypos - (height / 2)) / (height / 2));

			g_vertices.push_back(Vector3f(g_X1, g_Y1, 0.f));
			g_vertices.push_back(Vector3f(g_X2, g_Y2, 0.f));
		}

	}
}

void KeyHandler::startKeysTrack(const RenderWindow& window)
{
    glfwSetMouseButtonCallback(window.m_window, KeyHandler::mouseButtonCallback);
    glfwSetKeyCallback(window.m_window, KeyHandler::keyboardCallback);
}
void KeyHandler::startBoardTrack(const RenderWindow& window)
{
	glfwSetKeyCallback(window.m_window, KeyHandler::keyboardCallback);
}
void KeyHandler::startMouseTrack(const RenderWindow& window, void(*mouseCallback)(GLFWwindow*, int, int, int))
{
	glfwSetMouseButtonCallback(window.m_window, mouseCallback);
}
void KeyHandler::startMouseTrack(const RenderWindow& window)
{
	glfwSetMouseButtonCallback(window.m_window, KeyHandler::mouseButtonCallback);
}

// std::pair<Vector2f, Vector2f> KeyHandler::getLocalMouseCoords(const Vector2f& screenCoords)
// {
// 	return std::make_pair(Vector2f((sMouseCoordsPress.x - (screenCoords.x / 2)) / (screenCoords.x / 2),
// 				                   (sMouseCoordsPress.y - (screenCoords.y / 2)) / (screenCoords.y / 2)),
// 					      Vector2f((sMouseCoordsRelease.x - (screenCoords.x / 2)) / (screenCoords.x / 2),
// 							       (sMouseCoordsRelease.y - (screenCoords.y / 2)) / (screenCoords.y / 2)));
// }

}
