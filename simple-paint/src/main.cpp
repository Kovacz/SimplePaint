#include "application.h"
#include "engine.h"

using namespace mlg;
using namespace mlg::Core;

int main() {
    MAKE_APP();

    Engine engine;
    if (!engine.load()) {
        std::cerr << "Failed to load engine" << std::endl;
    }
    engine.run();
}
