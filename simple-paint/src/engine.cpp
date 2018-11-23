#include "engine.h"
#include "shader.h"
#include "graphicsystem.h"

#define COLOR_WHITE 1.f, 1.f, 1.f

const static char *VERTEX_SHADER_PATH = "../../shaders/texture_vert_shader.vert";
const static char *FRAGMENT_SHADER_PATH = "../../shaders/texture_frag_shader.frag";

namespace mlg
{

using Graphics::VertexShader;
using Graphics::FragmentShader;

bool Engine::load() noexcept
{
	if (!m_shaderProgram.build(VertexShader(VERTEX_SHADER_PATH), FragmentShader(FRAGMENT_SHADER_PATH)))	{
        std::cerr << "ERROR::ENGINE::LOAD 'failed to build shaders'" << std::endl;
		return false;
	}
	return true;
}

void Engine::run() noexcept
{

    while(!glfwWindowShouldClose(Application::getInstance()->window())) {

        Application::getInstance()->setBgColor(COLOR_WHITE, 1.f);

        m_shaderProgram.run();
        m_systemManager.get<Core::GraphicSystem>()->draw();

        Application::getInstance()->display();

        while(!Application::getInstance()->empty()) {
            m_systemManager.processEvent();
        }
    }

}

} // namespace mlg
