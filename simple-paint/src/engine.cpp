#include "engine.h"
#include "global.h"
#include "shader.h"

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
		std::cerr << "ERROR::УТПШТУ::LOAD 'failed to build shaders'" << std::endl;
		return false;
	}
	return true;
}

void Engine::run(Scene const& scene) noexcept
{
    Global::brush = Global::entity_manager.create<Core::Brush>();
    glfwSetMouseButtonCallback(scene.m_window.getHandle(), Global::mouseCallback);
    glfwSetKeyCallback(scene.m_window.getHandle(), Global::keyCallback);

	while(scene) {
		scene.setBgColor(COLOR_WHITE, 1.f);

		m_shaderProgram.run();

		scene.display();

        while(!Global::events_pool.empty()) {
            m_systemManager.processEvent();
        }
    }

}

} // namespace mlg
