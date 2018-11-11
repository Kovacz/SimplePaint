#include <catch2/catch.hpp>

#include "scene.h"

using namespace mlg::Graphics;

SCENARIO("scene creating", "[Scene]") {

    GIVEN("class that represent scene as set of resources") {
        WHEN("the scene was created") {
            AND_WHEN("all resources was loaded") {
                auto scene = Scene::make_scene();
                scene.load();
                THEN("the returned value must be true") {
                    REQUIRE(scene.load());
                }
            }
        }
    }
}
