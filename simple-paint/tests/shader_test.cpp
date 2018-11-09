#include <catch2/catch.hpp>

#include "shader.h"

using namespace mlg::Graphics;

SCENARIO("shader loading", "[Shader]") {

    GIVEN("no shaders") {
        Shader shader;
        WHEN("it is loaded") {
            THEN("an any errors must be thrown") {
                REQUIRE_THROWS(shader.loadFromFile(NULL, NULL));
            }
        }
    }

    GIVEN("a vertex shader") {
        AND_GIVEN("a fragment shader") {
            Shader shader;
            const static char* VERTEX   = "../../shaders/texture_vert_shader.vert";
            const static char* FRAGMENT = "../../shaders/texture_frag_shader.frag";
            WHEN("it is loaded") {
                THEN("an any errors can't be thrown") {
                    REQUIRE_NOTHROW(shader.loadFromFile(VERTEX, FRAGMENT));
                }
            }
        }
    }
}

SCENARIO("building shader program", "[Shader]") {

    GIVEN("")
}
