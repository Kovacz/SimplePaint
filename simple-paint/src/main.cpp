#include "engine.h"
#include "scenemanager.h"

using namespace mlg;
using namespace mlg::Core;

int main()
{
	SceneManager scene_manager;
	auto scene = scene_manager.create();

    Global::brush = Global::entity_manager.create<Core::Brush>();
    glfwSetMouseButtonCallback(scene(), Global::mouseCallback);
    glfwSetKeyCallback(scene(), Global::keyCallback);

	Engine engine;
	if (!engine.load()) {
		std::cerr << "Failed to load engine" << std::endl;
	}
	engine.run(scene);
}

