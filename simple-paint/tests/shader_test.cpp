#include <catch2/catch.hpp>

#include "shader.h"
#include "shaderbuilder.h"

using namespace mlg::Graphics;

SCENARIO("shader building", "[Shader]") {

    GIVEN("no shaders") {
        ShaderBuilder shaderProg;
        WHEN("it is builded") {
            THEN("a building must be failed") {
                REQUIRE_FALSE(shaderProg.build(VertexShader(""), FragmentShader("")));
            }
        }
    }

    GIVEN("a vertex shader") {
        AND_GIVEN("a fragment shader") {
            ShaderBuilder shaderProg;
            const static char* VERTEX   = "../../shaders/texture_vert_shader.vert";
            const static char* FRAGMENT = "../../shaders/texture_frag_shader.frag";
            WHEN("it is builded") {
                THEN("a building must be successful") {
                    REQUIRE(shaderProg.build(VertexShader(VERTEX), FragmentShader(FRAGMENT)));
                }
            }
        }
    }
}

SCENARIO("building shader program", "[Shader]") {

    //GIVEN("")
}
