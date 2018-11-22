#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <deque>

#include "vector3.hpp"
#include "brush.h"
#include "event.h"
#include "entitymanager.hpp"

namespace mlg
{

struct Global
{
	static Core::Brush* brush;
	static Core::EntityManager entity_manager;
	static std::deque<Core::Event*> events_pool;

	static Vec3d get_2d_ndc_coords(double const& x, double const& y);
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouseCallback(GLFWwindow* window, int button, int action, int mods);
	static void scrollCallback(GLFWwindow* window, double x, double y);
};

} // namespace mlg
