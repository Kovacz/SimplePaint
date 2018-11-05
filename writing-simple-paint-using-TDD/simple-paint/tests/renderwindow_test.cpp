#include <catch2/catch.hpp>
#include <tuple>

#include "../include/renderwindow.h"

using namespace mlg;

SCENARIO("getting window context params", "[RenderWindow]") {

    GIVEN("a RenderWindow with params width = 400, height = 250, window_name = Hello") {        
        WHEN("parameters of window setted in RenderWindow constructor") {
            RenderWindow window(400, 250, "Hello");
            THEN("the window context must be returned") {
                auto [width, height, name] = window.getWindowParams();
                REQUIRE(width);
                REQUIRE(height);
                REQUIRE(name);
            }
        }
    }
}

SCENARIO("creating window with empty params", "[RenderWindow]") {

    GIVEN("a RenderWindow with zero params") {
        RenderWindow window(NULL, NULL, NULL);
        WHEN("the window is created") {
            window.create();
            THEN("the window handle value must be NULL") {
                REQUIRE_FALSE(window.getHandle());
            }
        }
    }
}

SCENARIO("creating window with some params", "[RenderWindow]") {
    
    GIVEN("a RenderWindow with params width = 800, height = 800, window name = TestWindow") {
        RenderWindow window(800, 800, "TestWindow");
        WHEN("the window is created") {
            window.create();
            THEN("the window handle value can't be NULL") {
                REQUIRE(window.getHandle());
            }
        }
    }
}


