#ifndef CAMERA2D_H
#define CAMERA2D_H
#include "../include/vector2.hpp"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace mlg
{

class Camera2d
{
public:
	static float zoom;
	glm::mat4 getModelMat() const noexcept;
};

} // namespace mlg

#endif // CAMERA2D_H
