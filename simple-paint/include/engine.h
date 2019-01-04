#pragma once

#include "shaderbuilder.h"
#include "systemmanager.hpp"

namespace mlg {

class Engine final {
public:
    bool load() noexcept;
    void run() noexcept;

private:
    Core::SystemManager     m_systemManager;
    Graphics::ShaderBuilder m_shaderProgram;
};

} // namespace mlg
