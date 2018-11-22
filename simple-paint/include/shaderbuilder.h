#pragma once

#include <string>
#include <cstdint>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace mlg
{

namespace Graphics
{

class ShaderBuilder
{
private:
    void checkOnErrors(uint32_t const& handle, std::string&& type) const;
    bool compile(char const* vertexShaderCode, char const* fragmentShaderCode) noexcept;
	void deleteShaders();
	bool link() noexcept;
public:
	ShaderBuilder() noexcept = default;
	~ShaderBuilder() noexcept = default;
	// delete unused functionality
    ShaderBuilder(ShaderBuilder&&) = delete;
    ShaderBuilder(ShaderBuilder const&) = delete;
    ShaderBuilder& operator=(ShaderBuilder&&) = delete;
    ShaderBuilder& operator=(ShaderBuilder const&) = delete;
	// TODO: Geometry shader
    bool build(class VertexShader&& vert, class FragmentShader&& frag) noexcept;
	void run();
	uint32_t getShaderHandle() const noexcept;
private:
	uint32_t m_vertexShaderHandle;
	uint32_t m_fragmentShaderHandle;
	uint32_t m_shaderProgramHandle;
};

} // namespace Graphics

} // namespace mlg
