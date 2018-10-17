#include "../include/camera2d.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace mlg
{

float Camera2d::zoom = 1.f;

glm::mat4 Camera2d::getModelMat() const noexcept
{
	glm::vec3 scale = glm::vec3(Camera2d::zoom, Camera2d::zoom, 0.f);
	glm::mat4 model(1);
	model = glm::scale(model, scale);
	return model;
}

} // namespace mlg
