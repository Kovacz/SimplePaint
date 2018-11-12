#include <catch2/catch.hpp>

#include "multibuffer.hpp"

using namespace mlg::Graphics;

SCENARIO("generate buffers", "[Multibuffer]") {

    GIVEN("VBO") {
        WHEN("the buffers was generated") {
			MultiBuffer<VBO> buff;
			auto [vbo, vao, ebo] = buff.getBufferHandlers();
            THEN("the buffers handlers must be initialized") {
                REQUIRE(vbo);
             }
			AND_THEN("VAO's and EBO's handlers must be empty") {
				REQUIRE_FALSE(vao);
				REQUIRE_FALSE(ebo);
			}
        }
    }

	GIVEN("VBO, VAO") {
		WHEN("the buffers was generated") {
			MultiBuffer<VBO, VAO> buff;
			auto [vbo, vao, ebo] = buff.getBufferHandlers();
			THEN("the buffers handlers must be initialized") {
				REQUIRE(vbo);
				REQUIRE(vao);
			}
			AND_THEN("EBO's handler must be empty") {
				REQUIRE_FALSE(ebo);
			}
		}
	}

	GIVEN("VBO, VAO, EBO") {
		WHEN("the buffers was generated") {
			MultiBuffer<VBO, VAO, EBO> buff;
			auto [vbo, vao, ebo] = buff.getBufferHandlers();
            THEN("the buffers handlers must be initialized") {
				REQUIRE(vbo);
				REQUIRE(vao);
				REQUIRE(ebo);
			}
		}
	}
}
