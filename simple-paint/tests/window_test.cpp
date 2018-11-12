#include <catch2/catch.hpp>

#include "window.h"

using namespace mlg;

SCENARIO("getting window context information", "[Window]") {

    GIVEN("window params: width = 400, height = 250, name = Hello") {
        WHEN("parameters of window setted in constructor") {
            System::Window window(400, 250, "Hello");
            THEN("the window information must be returned") {
                auto [width, height, name] = window.getInfo();
                REQUIRE(width);
                REQUIRE(height);
                REQUIRE(name);
            }
        }
    }
}

SCENARIO("creating window with empty params", "[Window]") {

    GIVEN("no window params") {
        System::Window window(NULL, NULL, NULL);
        WHEN("the window is created") {
            THEN("an exception must be thrown") {
                REQUIRE_THROWS(window.create());
                AND_THEN("the window handle value must be NULL") {
                    REQUIRE_FALSE(window.getHandle());
                }
            }
        }
    }
}

SCENARIO("creating window with some params", "[Window]") {
    
    GIVEN("window params: width = 800, height = 800, name = TestWindow") {
        System::Window window(800, 800, "TestWindow");
        WHEN("the window is created") {
            THEN("any exceptions cannot be thrown") {
                REQUIRE_NOTHROW(window.create());
                AND_THEN("the window handle value can't be NULL") {
                    REQUIRE(window.getHandle());
                }
            }            
        }
    }
}


