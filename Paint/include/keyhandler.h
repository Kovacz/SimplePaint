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
	static bool  mouseClicked;
//	static std::pair<Vector2f, Vector2f> getLocalMouseCoords(const Vector2f& screenCoords);
    static void	 startMouseTrack(const RenderWindow& window);
	static void	 startMouseTrack(const RenderWindow& window, void(*mouseCallback)(GLFWwindow*, int, int, int));
	static void  startBoardTrack(const RenderWindow& window);
    static void  startKeysTrack(const RenderWindow& window);
private:
// 	static Vector2f sMouseCoordsPress;
// 	static Vector2f sMouseCoordsRelease;
	static void  keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void  mouseButtonCallback(GLFWwindow* window, int scancode, int action, int mods);

};

} // namespace mlg

#endif // KEYHANDLER_H
