#include <catch2/catch.hpp>

#include "../include/renderwindow.h"

using namespace mlg;

SCENARIO("create window") {
    
    GIVEN("class that create window") {
        RenderWindow window(800, 800, "TestWindow");
        WHEN("window created") {
            THEN("the return cannot be NULL") {
                REQUIRE(window.getHandle());
            }
        }
    }
}


