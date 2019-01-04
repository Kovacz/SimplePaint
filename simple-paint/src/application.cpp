#include "application.h"
#include <glad/glad.h>
#include <iostream>

namespace mlg {

using namespace Core;

Application* Application::instance{nullptr};

Application::Application() : m_window(800, 600, "Paint") {
    try {
        m_window.create();
        m_window.setFramebufferSizeCallback();
        if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
            throw "Failed to load glad!";
        }
        m_pBrush = m_entityManager.create<Core::Brush>();
        glfwSetMouseButtonCallback(m_window.getHandle(), Application::mouseCallback);
        glfwSetKeyCallback(m_window.getHandle(), Application::keyCallback);
    } catch (char const* error) {
        std::cerr << error << std::endl;
    }
}

Application::~Application() noexcept {}

void Application::kill() noexcept {
    delete m_pBrush;
    m_pBrush = nullptr;
    delete Application::instance;
    Application::instance = nullptr;
    this->~Application();
}

Application* Application::getInstance() {
    if (!Application::instance) {
        assert(Application::preInit());
        // if all is ok, create instance
        Application::instance = new Application();
    }
    return Application::instance;
}

Application::operator bool() const noexcept { return m_window.isOpen(); }

void Application::display() const noexcept {
    glfwSwapBuffers(m_window.getHandle());
    glfwWaitEvents();
}

void Application::setBgColor(float const& r, float const& g, float const& b, float const& a) const noexcept {
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

bool Application::empty() const noexcept { return m_eventsPool.empty(); }

Core::Brush* Application::entity() const noexcept { return m_pBrush; }

GLFWwindow* Application::window() const noexcept { return m_window.getHandle(); }

Core::Event* Application::getFrontEvent() const noexcept { return m_eventsPool.front(); }

void Application::popFrontEvent() noexcept { m_eventsPool.pop_front(); }

bool Application::preInit() {
    if (GLFW_FALSE == glfwInit()) {
        std::cerr << "glfwInit() function fails" << std::endl;
        return false;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, true);
#endif
    return true;
}

void Application::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_L && action == GLFW_PRESS) {
        Event* keyEvent = new Event(Application::getInstance()->m_pBrush);
        keyEvent->set<KeyboardAction>(EventType::KEY_PRESSED, key, scancode, mods);
        Application::getInstance()->m_eventsPool.emplace_back(keyEvent);
    }
}

void Application::mouseCallback(GLFWwindow* window, int button, int action, int mods) {
    double xpos = .0, ypos = .0;
    glfwGetCursorPos(window, &xpos, &ypos);

    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        Event* mouseEvent = new Event(Application::getInstance()->m_pBrush);
        mouseEvent->set<CursorPosition>(EventType::MOUSE_BUTTON_LEFT_PRESSED, xpos, ypos);
        Application::getInstance()->m_eventsPool.emplace_back(mouseEvent);
    } else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
        Event* mouseEvent = new Event(Application::getInstance()->m_pBrush);
        mouseEvent->set<CursorPosition>(EventType::MOUSE_BUTTON_LEFT_RELEASED, xpos, ypos);
        Application::getInstance()->m_eventsPool.emplace_back(mouseEvent);
    }
}

void Application::scrollCallback(GLFWwindow* window, double x, double y) {}

} // namespace mlg
