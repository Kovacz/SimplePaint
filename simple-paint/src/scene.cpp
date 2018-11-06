#include "scene.h"
#include "glad/glad.h"
#include <iostream>

namespace mlg
{

namespace Graphics
{

Scene::Scene()
{    
    try {
        m_pWindow = new System::Window(800, 800, "asd");
        m_pWindow->create(); 
    }
    catch(char const* e) {
        std::cerr << e << std::endl;
    }     
}

Scene::~Scene()
{
    // TODO: assert if window = nullptr
    delete m_pWindow;
}

void Scene::onDraw()
{

}

void Scene::onUpdate()
{

}

void Scene::load()
{

}

void Scene::display() const noexcept
{
    glfwSwapBuffers(m_window.getHandle());
	glfwPollEvents();
}

void Scene::setBgColor(float const& r, float const& g, float const& b, float const& a) const noexcept
{
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

} // namespace Graphics

} // namespace mlg