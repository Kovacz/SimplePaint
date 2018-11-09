#include "scene.h"

using namespace mlg::Graphics;

int main()
{
    auto scene = Scene::make_scene();
    scene.load();


    /*
    auto renderer = Renderer::make_renderer();
    renderer.render(scene);
    */

    return 0;
}
