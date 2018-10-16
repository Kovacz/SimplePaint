#ifndef DEFINES_HPP
#define DEFINES_HPP

#include <GLFW/glfw3.h>
#include <vector>
#include <cmath>
#include "../include/vector3.hpp"
#include "../include/drawmode.h"

#define COLOR_WHITE 1.f, 1.f, 1.f

const static int WIDTH = 800;
const static int HEIGHT = 600;
const static char* VERTEX_SHADER_PATH   = "../../src/texture_vert_shader.vert";
const static char* FRAGMENT_SHADER_PATH = "../../src/texture_frag_shader.frag";

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
extern unsigned textureVAO;
extern unsigned drawableVAO;

inline void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

inline const float& vecDistance(const Vector3f& vec1, const Vector3f& vec2)
{
    Vector3f substract;
    substract.x = vec1.x - vec2.x;
    substract.y = vec1.y - vec2.y;
    substract.z = vec1.z - vec2.z;
    return sqrt(pow(substract.x, 2) + pow(substract.y, 2) + pow(substract.z, 2));
}

} // namespace mlg

#endif // DEFINES_HPP
