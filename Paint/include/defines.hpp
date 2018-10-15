#ifndef DEFINES_HPP
#define DEFINES_HPP

#include <GLFW/glfw3.h>
#include <vector>
#include "include/vector3.hpp"
#include "include/drawmode.h"

#define COLOR_WHITE 1.f, 1.f, 1.f

const static int WIDTH = 800;
const static int HEIGHT = 600;
const static char* VERTEX_SHADER_PATH   = "../src/shaders/vert_shader.vert";
const static char* FRAGMENT_SHADER_PATH = "../src/shaders/frag_shader.frag";

namespace mlg
{
//class DrawMode;

typedef std::vector<Vector3f> Vertex3;

extern DrawMode& singleDrawMode;

//extern bool		g_drawFlag;
extern float	g_X1;
extern float	g_Y1;
extern float	g_X2;
extern float	g_Y2;
extern Vertex3  g_vertices;
extern std::size_t index;

inline void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

} // namespace mlg

#endif // DEFINES_HPP
