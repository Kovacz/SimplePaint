#include "../include/keyhandler.h"
#include "../include/renderwindow.h"
#include "../include/camera2d.h"
#include <iostream>

namespace mlg
{
// Vector2f KeyHandler::sMouseCoordsPress(0.f, 0.f);
// Vector2f KeyHandler::sMouseCoordsRelease(0.f, 0.f);
bool KeyHandler::mouseClicked = false;
bool KeyHandler::mouseRelease = false;

void KeyHandler::keyboardCallback(GLFWwindow* window
		, int key
		, int scancode
		, int action
		, int mods
		)
{
	if (key == GLFW_KEY_L && action == GLFW_PRESS)
	{
        //g_linesVert.clear();
        g_linesMode = 1;
		singleDrawMode.setMode(DrawMode::LINES_MODE);
	}
	else if (key == GLFW_KEY_S && action == GLFW_PRESS)
	{
        //g_stripVert.clear();
        g_stripMode = 1;
		singleDrawMode.setMode(DrawMode::LINES_STRIP_MODE);
	}
	else if (key == GLFW_KEY_B && action == GLFW_PRESS)
	{
        //g_brushVert.clear();
        g_brushMode = 1;
		singleDrawMode.setMode(DrawMode::BRUSH_MODE);
	}
	else if (key == GLFW_KEY_C && action == GLFW_PRESS)
	{
        //g_circleVert.clear();
        g_circleMode = 1;
		singleDrawMode.setMode(DrawMode::CIRCLE_MODE);
	}
    else if (key == GLFW_KEY_N && action == GLFW_PRESS)
    {
        //g_vertices.clear();
        g_bgMode = 1;
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
        mouseRelease = false;

        if (singleDrawMode.getModeState() != DrawMode::BRUSH_MODE)
        {
            g_X1 = static_cast<float>( (xpos - (width  / 2)) / (width  / 2));
            g_Y1 = static_cast<float>(-(ypos - (height / 2)) / (height / 2));
        }
    }
    else if (action == GLFW_RELEASE)
	{
		mouseClicked = false;

        singleDrawMode.setDrawFlag(true);


        g_X2 = static_cast<float>( (xpos - (width  / 2)) / (width  / 2));
        g_Y2 = static_cast<float>(-(ypos - (height / 2)) / (height / 2));

        if (singleDrawMode.getModeState() == DrawMode::LINES_MODE)
        {
            g_linesVert.push_back(Vector3f(g_X1, g_Y1, 0.f));
            g_linesVert.push_back(Vector3f(g_X2, g_Y2, 0.f));
        }
        else if (singleDrawMode.getModeState() == DrawMode::LINES_STRIP_MODE)
        {
            g_stripVert.push_back(Vector3f(g_X1, g_Y1, 0.f));
        }
        else if (singleDrawMode.getModeState() == DrawMode::CIRCLE_MODE)
        {
            g_circleVert.push_back(Vector3f(g_X1, g_Y1, 0.f));
            g_circleVert.push_back(Vector3f(g_X2, g_Y2, 0.f));
        }

        mouseRelease = true;
	}
}

void KeyHandler::startKeysTrack(const RenderWindow& window)
{
    glfwSetMouseButtonCallback(window.m_window, KeyHandler::mouseButtonCallback);
    glfwSetKeyCallback(window.m_window, KeyHandler::keyboardCallback);
	glfwSetScrollCallback(window.m_window, KeyHandler::mouseScrollCallback);
}
void KeyHandler::mouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset)
{
	if (Camera2d::zoom >= 1.f && Camera2d::zoom <= 45.f)
		Camera2d::zoom -= static_cast<float>(yOffset);
	else if (Camera2d::zoom <= 1.f)
		Camera2d::zoom = 1.f;
	else if (Camera2d::zoom >= 45.f)
		Camera2d::zoom = 45.f;
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
