#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H


#include "../include/vertexbuffer.h"
#include "../include/circleshape.h"

namespace mlg
{

class  KeyHandler;
struct Vertex;
class  Texture;
class  Camera2d;

class RenderWindow
{
	friend KeyHandler;

public:
	RenderWindow(int width, int height, const char* wndName, GLFWmonitor *monitor = nullptr, GLFWwindow *share = nullptr);
	~RenderWindow();

	void draw();
    void draw(const Texture& texture, CircleShape& circle) const;
	void draw(const Vertex* vertices) const;
	void close() const;
	void create();
	void display() const;
	bool isOpen() const;
	void setBgColor(const float& r, const float& g, const float& b, const float& a) const noexcept;
protected:
	bool gladLoad() const;
public:
	int             m_width;
	int             m_height;
	const char*     m_cWindowName;
	GLFWmonitor*    m_monitor;
	GLFWwindow*     m_share;
	GLFWwindow*     m_window;
    std::vector<VertexBuffer> m_buff;
};

} // namespace mlg

#endif // RENDERWINDOW_H
