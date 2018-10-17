#include "../include/camera2d.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace mlg
{

Camera2d::Camera2d(
        const glm::vec3& pos /* = glm::vec3(0.f, 0.f, 0.f) */,
        const glm::vec3& up  /* = glm::vec3(0.f, 1.f, 0.f) */
        )
        : m_zoom(45.f)
        , m_yaw(-90.f)
        , m_pitch(0.f)
        , position(pos)
        , worldUp(up)
        , front(glm::vec3(0.f, 0.f, -1.f))
{
    this->update();
}
void Camera2d::setZoom(const float& zoom)
{
    this->m_zoom = zoom;
}
float Camera2d::getZoom() const noexcept
{
    return this->m_zoom;
}
glm::mat4 Camera2d::getViewMatrix() const noexcept
{
    return glm::lookAt(this->position, this->position + this->front, this->up);
}

void Camera2d::mouseScrollCallback(const float& yOffset)
{
    if (m_zoom >= 1.f && m_zoom <= 45.f)
        m_zoom -= yOffset;
    else if (m_zoom <= 1.f)
        m_zoom = 1.f;
    else if (m_zoom >= 45.f)
        m_zoom = 45.f;
}

void Camera2d::update()
{
    // Calculate the new Front vector
    glm::vec3 _front;
    _front.x = cos(glm::radians(this->m_yaw)) * cos(glm::radians(this->m_pitch));
    _front.y = sin(glm::radians(this->m_pitch));
    _front.z = cos(glm::radians(this->m_pitch)) * sin(glm::radians(this->m_yaw));
    this->front = glm::normalize(_front);
    // Also re-calculate the Right and Up vector
    this->right = glm::normalize(glm::cross(this->front, this->worldUp));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    this->up = glm::normalize(glm::cross(this->right, this->front));
}

} // namespace mlg
