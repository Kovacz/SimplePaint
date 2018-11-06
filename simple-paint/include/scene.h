#pragma once 


#include "window.h"
#include "camera.h"

namespace mlg
{

namespace Graphics
{

class Scene 
{
public:

    Scene();
    ~Scene() noexcept;
    
    void onDraw();
    void onUpdate();   

    void load();

    void display() const noexcept;
    void setBgColor(float const& r, float const& g, float const& b, float const& a) const noexcept;

private:
    System::Window* m_pWindow {nullptr};
    Graphics::Camera m_camera;
};

} // namespace Graphics

} // namespace mlg