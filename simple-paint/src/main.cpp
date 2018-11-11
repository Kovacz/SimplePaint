#include "scene.h"
#include "renderer.h"

using namespace mlg::Graphics;

int main()
{
	auto scene = Scene::make_scene();
	scene.load();

	auto renderer = Renderer::make_renderer();
	renderer.add(&scene);

	renderer.render();


	return 0;
}
