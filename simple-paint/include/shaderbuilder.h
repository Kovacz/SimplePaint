#pragma once

#include <cstdint>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>

namespace mlg {

namespace Graphics {

class ShaderBuilder {
public:
    ShaderBuilder() noexcept  = default;
    ~ShaderBuilder() noexcept = default;

    // delete unused functionality
    ShaderBuilder(ShaderBuilder&&)      = delete;
    ShaderBuilder(ShaderBuilder const&) = delete;
    ShaderBuilder& operator=(ShaderBuilder&&) = delete;
    ShaderBuilder& operator=(ShaderBuilder const&) = delete;

    // TODO: Geometry shader
    bool build(class VertexShader&& vert, class FragmentShader&& frag) noexcept;

    void run();

    uint32_t getShaderHandle() const noexcept;

private:
    void checkOnErrors(uint32_t const& handle, std::string&& type) const;

    bool compile(char const* vertexShaderCode, char const* fragmentShaderCode) noexcept;

    void deleteShaders();

    bool link() noexcept;

    // data
    uint32_t m_vertexShaderHandle;
    uint32_t m_fragmentShaderHandle;
    uint32_t m_shaderProgramHandle;
};

} // namespace Graphics

} // namespace mlg
