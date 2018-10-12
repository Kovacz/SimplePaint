#include "../include/keyhandler.h"
#include <iostream>
using mlg::KeyHandler;

void KeyHandler::startMouseTrack(GLFWwindow* window
        , int button
        , int action
        , int mods
        )
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
       double xpos, ypos;
       //getting cursor position
       glfwGetCursorPos(window, &xpos, &ypos);
       std::cout << "Cursor Position at " << xpos << " : " << ypos << std::endl;
    }
}
