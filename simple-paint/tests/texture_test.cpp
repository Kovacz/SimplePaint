#include <catch2/catch.hpp>

#include "texture.h"

using namespace mlg::Graphics;

SCENARIO("generating a texture", "[Texture]") {

    GIVEN("a Texture entity") {
        Texture texture;
        WHEN("texture was generated") {
            texture.generate();
            THEN("the handle of which must be returned") {
                REQUIRE(texture.getHandle());
            }
        }
    }
}

SCENARIO("loading image from file", "[Texture]") {

    GIVEN("a Texture entity") {
        AND_GIVEN("no image to load") {
            Texture texture;
            WHEN("texture was generated") {
                AND_WHEN("the image was absent") {
                    texture.generate();
                    texture.loadFromFile("");
                    THEN("an image data must be empty") {
                        REQUIRE_FALSE(texture.getImage());
                    }
                    AND_THEN("a width and height must be zero") {
                        auto [width, height] = texture.getInfo();
                        REQUIRE_FALSE(width);
                        REQUIRE_FALSE(height);
                    }
                }
            }
        }
    }

    GIVEN("a Texture entity") {
        AND_GIVEN("image: 'windows.jpg'") {
            Texture texture;
            WHEN("texture was generated") {
                AND_WHEN("the image was loaded from file") {
                    texture.generate();
                    texture.loadFromFile("../../windows.jpg");
                    THEN("an image data must be returned") {
                        REQUIRE(texture.getImage());
                    }
                    AND_THEN("a width and height must be returned") {
                        auto [width, height] = texture.getInfo();
                        REQUIRE(width);
                        REQUIRE(height);
                    }
                }
            }
        }
    }
}
