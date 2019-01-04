#include <catch2/catch.hpp>

#include "graphicsystem.h"
#include "line.h"

using namespace mlg;
using namespace mlg::Core;
using namespace mlg::Graphics;

class Mouse
{
public:
    std::vector<Vec3d> getCoords()
    {
        std::vector<Vec3d> randCoords;
        randCoords.push_back({0.5, 1.0, 0.0});
        randCoords.push_back({-0.5, -1.0, 0.0});
        return randCoords;
    }

private:

} mouse;

SCENARIO("drawing lines", "[GraphicSystem]") {

    GIVEN("a line-component") {
        Line lines;
        AND_GIVEN("a graphic system") {
            GraphicSystem gsys;
            WHEN("the component got the vertices") {
                lines.vertices = mouse.getCoords();
                THEN("a graphic system can update buffers with new vertices") {
                    REQUIRE(gsys.update(&lines));
                }
                AND_THEN("draw them as lines") {
                    REQUIRE(gsys.draw());
                }
            }
        }
    }
}
