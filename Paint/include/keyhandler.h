#ifndef KEYHANDLER_H
#define KEYHANDLER_H
#include <GLFW/glfw3.h>

namespace mlg
{

struct KeyHandler
{
    static void startMouseTrack(GLFWwindow* window, int button, int action, int mods);
};

} // namespace mlg

#endif // KEYHANDLER_H
