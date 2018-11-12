#include <catch2/catch.hpp>

#include "scene.h"

using namespace mlg::Graphics;

SCENARIO("scene creating", "[Scene]") {

    GIVEN("class that represent scene") {
        WHEN("the scene was created") {
            AND_WHEN("all entities was loaded") {
                auto scene = Scene::make_scene();
                scene.load();
                THEN("the returned value must be true") {
                    REQUIRE(scene.load());
                }
            }
        }
    }
}
