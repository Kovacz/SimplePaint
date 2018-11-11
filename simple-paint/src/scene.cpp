#include "scene.h"
#include <glad/glad.h>
#include <iostream>
#include "shader.h"

const static char* VERTEX_SHADER_PATH   = "../../shaders/texture_vert_shader.vert";
const static char* FRAGMENT_SHADER_PATH = "../../shaders/texture_frag_shader.frag";

namespace mlg
{

namespace Graphics
{

Scene::Scene()
{    
    try {
        m_pWindow = new System::Window(800, 600, "Paint");
        m_pWindow->create(); 
        m_pWindow->setFramebufferSizeCallback();
        this->gladInit();
    }
    catch (char const* e) {
        std::cerr << e << std::endl;
    }

    m_pTexture = new Graphics::Texture;
    m_pTexture->generate();
}

Scene::~Scene() noexcept
{    
    delete m_pWindow;
    delete m_pTexture;
}
Scene::operator bool() const noexcept
{
	return m_pWindow->isOpen();
}

Scene Scene::make_scene()
{
    return Scene();
}

void Scene::gladInit() const
{
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        throw "Scene::gladInit - failed to load GLAD\n";
    }
}

bool Scene::load() noexcept
{
    if (!m_pTexture) {
        std::cerr << "Scene::load - texture was not created" << std::endl;
        return false;
    }
    if (!m_pTexture->loadFromFile("../../windows.jpg")) {
        std::cerr << "Scene::load - failed to load texture from file" << std::endl;
        return false;
    }
    if (!m_shaderProgram.build(VertexShader(VERTEX_SHADER_PATH), FragmentShader(FRAGMENT_SHADER_PATH))) {
        std::cerr << "Scene::load - failed to build shaders" << std::endl;
        return false;
    }
	return true;
}

void Scene::onDraw()
{
	Graphics::Texture::bind(m_pTexture);
	m_shaderProgram.run();
	//shaderProg.setMat4("model", camera.getModelMat());
	//myWindow.draw(texture);
	//myWindow.display();
}

void Scene::onUpdate()
{

}

void Scene::display() const noexcept
{
    glfwSwapBuffers(m_pWindow->getHandle());
	glfwPollEvents();
}

void Scene::setBgColor(float const& r, float const& g, float const& b, float const& a) const noexcept
{
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

} // namespace Graphics

} // namespace mlg
