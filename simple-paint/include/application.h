#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <deque>

#include "brush.h"
#include "camera.h"
#include "entitymanager.hpp"
#include "event.h"
#include "window.h"

#define MAKE_APP() Application::getInstance()

namespace mlg {

class Application final {
    using EventPool = std::deque<Core::Event*>;
    using Brush     = Core::Brush;
    using Event     = Core::Event;

public:
    static Application* getInstance();
    explicit            operator bool() const noexcept;

    void        kill() noexcept;
    void        display() const noexcept;
    void        setBgColor(float const& r, float const& g, float const& b, float const& a) const noexcept;
    bool        empty() const noexcept;
    Brush*      entity() const noexcept;
    GLFWwindow* window() const noexcept;
    Event*      getFrontEvent() const noexcept;
    void        popFrontEvent() noexcept;

private:
    Application();
    ~Application() noexcept;
    // deleted
    Application(Application&&)      = delete;
    Application(Application const&) = delete;
    Application& operator=(Application&&) = delete;
    Application& operator=(Application const&) = delete;
    // for self use
    static bool preInit();
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void mouseCallback(GLFWwindow* window, int button, int action, int mods);
    static void scrollCallback(GLFWwindow* window, double x, double y);

private:
    static Application* instance;

    Core::Brush*        m_pBrush;
    Core::EntityManager m_entityManager;
    Graphics::Window    m_window;
    Graphics::Camera    m_camera;
    EventPool           m_eventsPool;
};

} // namespace mlg
