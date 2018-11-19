#include "scene.h"
#include "shader.h"
#include "event.h"
#include <glad/glad.h>
#include <iostream>

const static char *VERTEX_SHADER_PATH = "../../shaders/texture_vert_shader.vert";
const static char *FRAGMENT_SHADER_PATH = "../../shaders/texture_frag_shader.frag";

namespace mlg
{

namespace Graphics
{

Core::Brush* Scene::brush = nullptr;
std::deque<Event*> Scene::events_pool;

Scene::Scene()
{
	try	{
		m_pWindow = new System::Window(800, 600, "Paint");
		m_pWindow->create();
		m_pWindow->setFramebufferSizeCallback();
		this->gladInit();

        brush = m_emanager.create<Core::Brush>();

		glfwSetKeyCallback(m_pWindow->getHandle(), Scene::keyCallback);
		glfwSetMouseButtonCallback(m_pWindow->getHandle(), Scene::mouseCallback);
		glfwSetScrollCallback(m_pWindow->getHandle(), Scene::scrollCallback);
	}
	catch (char const *e) {
		std::cerr << e << std::endl;
	}
	// m_pTexture = new Graphics::Texture;
	// m_pTexture->generate();
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

void Scene::gladInit() const
{
	if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
		throw "ERROR::SCENE::GLAD_INIT 'failed to load GLAD'\n";
	}
}

void Scene::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{

	if (key == GLFW_KEY_L && action == GLFW_PRESS)
	{

	}
	else if (key == GLFW_KEY_S && action == GLFW_PRESS)
	{

	}
	else if (key == GLFW_KEY_B && action == GLFW_PRESS)
	{

	}
	else if (key == GLFW_KEY_C && action == GLFW_PRESS)
	{

	}
    else if (key == GLFW_KEY_N && action == GLFW_PRESS)
    {

    }
    else if (key == GLFW_KEY_F1 && action == GLFW_PRESS)
    {

    }
}

void Scene::mouseCallback(GLFWwindow* window, int button, int action, int mods)
{
    Core::Event* mouseEvent = new Core::Event(brush);
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        mouseEvent->set<Core::MouseAction>(Core::EventType::MOUSE_BUTTON_LEFT_PRESSED, button, mods);
        events_pool.emplace_back(mouseEvent);
    }
    else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
        mouseEvent->set<Core::MouseAction>(Core::EventType::MOUSE_BUTTON_LEFT_RELEASED, button, mods);
        events_pool.emplace_back(mouseEvent);
    }
}

void Scene::scrollCallback(GLFWwindow* window, double x, double y)
{

}

bool Scene::load() noexcept
{
	if (!m_pTexture) {
		std::cerr << "ERROR::SCENE::LOAD 'texture was not created'" << std::endl;
		return false;
	}
	if (!m_pTexture->loadFromFile("../../windows.jpg"))	{
		std::cerr << "ERROR::SCENE::LOAD 'failed to load texture from file'" << std::endl;
		return false;
	}
	if (!m_shaderProgram.build(VertexShader(VERTEX_SHADER_PATH), FragmentShader(FRAGMENT_SHADER_PATH)))	{
		std::cerr << "ERROR::SCENE::LOAD 'failed to build shaders'" << std::endl;
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

void Scene::setBgColor(float const &r, float const &g, float const &b, float const &a) const noexcept
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);
}

} // namespace Graphics

} // namespace mlg
