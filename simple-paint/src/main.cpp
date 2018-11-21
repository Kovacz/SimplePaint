#include "engine.h"
#include "scenemanager.h"

using namespace mlg;
using namespace mlg::Core;

int main()
{
	SceneManager scene_manager;
	auto scene = scene_manager.create();

	Engine engine;
	if (!engine.load()) {
		std::cerr << "Failed to load engine" << std::endl;
	}
	engine.run(scene);
}

