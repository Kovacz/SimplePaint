#include "../include/keyhandler.h"
#include "../include/renderwindow.h"
#include "../include/globaldefines.h"
#include "../include/defines.hpp"
#include "../include/camera2d.h"
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
        singleGlobalDefines.lines_mode = true;
		singleGlobalDefines.setMode(GlobalDefines::LINES_MODE);
	}
	else if (key == GLFW_KEY_S && action == GLFW_PRESS)
	{
		singleGlobalDefines.setMode(GlobalDefines::LINES_STRIP_MODE);
	}
	else if (key == GLFW_KEY_B && action == GLFW_PRESS)
	{
        KeyHandler::mouseClicked  = false;
        KeyHandler::mouseReleased = false;
        singleGlobalDefines.brush_mode = true;
		singleGlobalDefines.setMode(GlobalDefines::BRUSH_MODE);
	}
	else if (key == GLFW_KEY_C && action == GLFW_PRESS)
	{
        KeyHandler::mouseClicked  = false;
        KeyHandler::mouseReleased = false;
        singleGlobalDefines.circle_mode = true;
		singleGlobalDefines.setMode(GlobalDefines::CIRCLE_MODE);
	}
    else if (key == GLFW_KEY_N && action == GLFW_PRESS)
    {
        singleGlobalDefines.texture_mode = true;
        singleGlobalDefines.setMode(GlobalDefines::LOAD_BG_MODE);
    }
    else if (key == GLFW_KEY_F1 && action == GLFW_PRESS)
    {
        singleGlobalDefines.setMode(GlobalDefines::SAVE_MODE);
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
        if (singleGlobalDefines.getModeState() != GlobalDefines::BRUSH_MODE
		 && singleGlobalDefines.getModeState() != GlobalDefines::LOAD_BG_MODE)
        {
			singleGlobalDefines.mouseClickedCoords = get_2d_ndc_coord(xpos, ypos);
        }
    }
    else if (action == GLFW_RELEASE)
	{
		KeyHandler::mouseClicked  = false;
		KeyHandler::mouseReleased = true;

		singleGlobalDefines.setDrawFlag(true);

		if (singleGlobalDefines.getModeState() != GlobalDefines::BRUSH_MODE
		 && singleGlobalDefines.getModeState() != GlobalDefines::LOAD_BG_MODE)
		{
			singleGlobalDefines.mouseReleasedCoords = get_2d_ndc_coord(xpos, ypos);
		}
		if (singleGlobalDefines.getModeState() == GlobalDefines::LINES_MODE)
		{
			singleGlobalDefines.linesVertArray.push_back(singleGlobalDefines.mouseClickedCoords);
			singleGlobalDefines.linesVertArray.push_back(singleGlobalDefines.mouseReleasedCoords);
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

}
