#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <tuple>

namespace mlg {

namespace Graphics {

class Window {
    using info   = std::tuple<unsigned, unsigned, char const*>;
    using handle = GLFWwindow*;

public:
    Window(int width, int height, char const* name);
    ~Window() noexcept;

    void close() const noexcept;

    void create();

    bool isOpen() const noexcept;

    void setFramebufferSizeCallback() const;

    info   getInfo() const noexcept;
    handle getHandle() const noexcept;

private:
    int m_width{0u};
    int m_height{0u};

    char const* m_name{nullptr};

    GLFWwindow* m_handle{nullptr};
};

} // namespace Graphics

} // namespace mlg
