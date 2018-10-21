#ifndef KEYHANDLER_H
#define KEYHANDLER_H
#include <GLFW/glfw3.h>
#include <utility>

namespace mlg
{
class RenderWindow;
class Camera2d;

class KeyHandler
{
public:
	static void  startTrack(const RenderWindow& window);
    static void	 startMouseTrack(const RenderWindow& window);
	static void	 startMouseTrack(const RenderWindow& window, void(*mouseCallback)(GLFWwindow*, int, int, int));
	static void  startBoardTrack(const RenderWindow& window);
private:
	static void  keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void  mouseButtonCallback(GLFWwindow* window, int scancode, int action, int mods);
	static void  mouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset);
public:
	static bool  mouseClicked;
	static bool  mouseReleased;
};

} // namespace mlg

#endif // KEYHANDLER_H
