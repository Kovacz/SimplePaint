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
    Camera2d(const glm::vec3& pos = glm::vec3(0.f, 0.f, 0.f),
             const glm::vec3& up  = glm::vec3(0.f, 1.f, 0.f));
   //~Camera2d();
    void        setZoom(const float& zoom);
    float       getZoom()       const noexcept;
    glm::mat4   getViewMatrix() const noexcept;
    void        mouseScrollCallback(const float& yOffset);
protected:
    void        update();
private:
    // Camera zoom
    float       m_zoom;
    // Euler Angles
    float       m_yaw;
    float       m_pitch;
public:
    // Camera Attributes
    glm::vec3   position;
    glm::vec3   worldUp;
    glm::vec3   front;
    glm::vec3   up;
    glm::vec3   right;
};

} // namespace mlg

#endif // CAMERA2D_H
