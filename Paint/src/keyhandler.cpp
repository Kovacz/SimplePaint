#include "../include/keyhandler.h"
#include "../include/renderwindow.h"
#include "../include/camera2d.h"
#include "../include/defines.hpp"
#include <iostream>

namespace mlg
{

bool KeyHandler::mouseClicked  = false;
bool KeyHandler::mouseReleased = false;

void KeyHandler::keyboardCallback(GLFWwindow* window
		, int key
		, int scancode
		, int action
		, int mods
		)
{
	if (key == GLFW_KEY_L && action == GLFW_PRESS)
	{
        singleDrawMode.lines_mode = true;
		singleDrawMode.setMode(DrawMode::LINES_MODE);
	}
	else if (key == GLFW_KEY_S && action == GLFW_PRESS)
	{
		singleDrawMode.setMode(DrawMode::LINES_STRIP_MODE);
	}
	else if (key == GLFW_KEY_B && action == GLFW_PRESS)
	{
        KeyHandler::mouseClicked  = false;
        KeyHandler::mouseReleased = false;
        singleDrawMode.brush_mode = true;
		singleDrawMode.setMode(DrawMode::BRUSH_MODE);
	}
	else if (key == GLFW_KEY_C && action == GLFW_PRESS)
	{
        KeyHandler::mouseClicked  = false;
        KeyHandler::mouseReleased = false;
        singleDrawMode.circle_mode = true;
		singleDrawMode.setMode(DrawMode::CIRCLE_MODE);
	}
    else if (key == GLFW_KEY_N && action == GLFW_PRESS)
    {
        singleDrawMode.texture_mode = true;
        singleDrawMode.setMode(DrawMode::LOAD_BG_MODE);
    }
    else if (key == GLFW_KEY_F1 && action == GLFW_PRESS)
    {
        singleDrawMode.setMode(DrawMode::SAVE_MODE);
    }
}

void KeyHandler::mouseButtonCallback(GLFWwindow* window
		, int scancode
		, int action
		, int mods
		)
{
	double xpos = .0, ypos = .0;
	glfwGetCursorPos(window, &xpos, &ypos);
	if (scancode == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		KeyHandler::mouseClicked  = true;
		KeyHandler::mouseReleased = false;
        if (singleDrawMode.getModeState() != DrawMode::BRUSH_MODE
		 && singleDrawMode.getModeState() != DrawMode::LOAD_BG_MODE)
        {
            g_X1 = static_cast<float>( (xpos - (WIDTH  / 2)) / (WIDTH  / 2));
            g_Y1 = static_cast<float>(-(ypos - (HEIGHT / 2)) / (HEIGHT / 2));
        }
    }
    else if (action == GLFW_RELEASE)
	{
		KeyHandler::mouseClicked  = false;
		KeyHandler::mouseReleased = true;

		singleDrawMode.setDrawFlag(true);

		if (singleDrawMode.getModeState() != DrawMode::BRUSH_MODE
		 && singleDrawMode.getModeState() != DrawMode::LOAD_BG_MODE)
		{
			g_X2 = static_cast<float>( (xpos - (WIDTH  / 2)) / (WIDTH  / 2));
			g_Y2 = static_cast<float>(-(ypos - (HEIGHT / 2)) / (HEIGHT / 2));
		}
		if (singleDrawMode.getModeState() == DrawMode::LINES_MODE)
		{
			g_vertices.push_back(Vector3f(g_X1, g_Y1, 0.f));
			g_vertices.push_back(Vector3f(g_X2, g_Y2, 0.f));
		}

	}
}

void KeyHandler::startTrack(const RenderWindow& window)
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
