#include "global.h"

namespace mlg
{

Core::Brush* Global::brush{nullptr};
Core::EntityManager Global::entity_manager;
std::deque<Core::Event*> Global::events_pool;
using namespace Core;

glm::dvec3 Global::get_2d_ndc_coords(double const& x, double const& y)
{
    return glm::dvec3(((x - (800 / 2)) / (800 / 2)), (-(y - (600 / 2)) / (600 / 2)), .0f);
}

void Global::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_L && action == GLFW_PRESS)
    {
        Event* keyEvent = new Event(brush);
        keyEvent->set<KeyboardAction>(EventType::KEY_PRESSED, key, scancode, mods);
        events_pool.emplace_back(keyEvent);
    }
}

void Global::mouseCallback(GLFWwindow* window, int button, int action, int mods)
{
    double xpos = .0, ypos = .0;
    glfwGetCursorPos(window, &xpos, &ypos);

	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        Event* mouseEvent = new Event(brush);
        mouseEvent->set<CursorPosition>(EventType::MOUSE_BUTTON_LEFT_PRESSED, xpos, ypos);
		events_pool.emplace_back(mouseEvent);
	}
	else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
        Event* mouseEvent = new Event(brush);
        mouseEvent->set<CursorPosition>(EventType::MOUSE_BUTTON_LEFT_RELEASED, xpos, ypos);
		events_pool.emplace_back(mouseEvent);
	}
}

void Global::scrollCallback(GLFWwindow* window, double x, double y)
{

}

} //namespace mlg
