#include "shaderbuilder.h"
#include <glad/glad.h>
#include <iostream>
#include "shader.h"

namespace mlg
{

namespace Graphics
{

void ShaderBuilder::checkOnErrors(uint32_t const &handle, std::string &&type) const
{
	int success;
	char infoLog[1024];
	if (type.compare("PROGRAM")) {
		glGetShaderiv(handle, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(handle, 1024, nullptr, infoLog);
			std::cerr << "ERROR::SHADER_BUILDER 'compile-time error' | Type: " << type << "\n"
					  << infoLog << "\n -- --------------------------------------------------- -- "
					  << std::endl;
			throw "Compile-time error";
		}
	}
	else {
		glGetProgramiv(handle, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(handle, 1024, nullptr, infoLog);
			std::cerr << "ERROR::SHADER_BUILDER 'link-time error' | Type: " << type << "\n"
					  << infoLog << "\n -- --------------------------------------------------- -- "
					  << std::endl;
			throw "Link-time error";
		}
	}
}

bool ShaderBuilder::compile(char const *vertexShaderCode, char const *fragmentShaderCode) noexcept
{
	try	{
		// Vertex Shader
		m_vertexShaderHandle = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(m_vertexShaderHandle, 1, &vertexShaderCode, nullptr);
		glCompileShader(m_vertexShaderHandle);
		this->checkOnErrors(m_vertexShaderHandle, "VERTEX");
		// Fragment Shader
		m_fragmentShaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(m_fragmentShaderHandle, 1, &fragmentShaderCode, nullptr);
		glCompileShader(m_fragmentShaderHandle);
		this->checkOnErrors(m_fragmentShaderHandle, "FRAGMENT");
		return true;
	}
	catch (char const *e) {
		std::cerr << e << std::endl;
		return false;
	}
}

bool ShaderBuilder::link() noexcept
{
	try	{
		// Shader Program
		m_shaderProgramHandle = glCreateProgram();
		glAttachShader(m_shaderProgramHandle, m_vertexShaderHandle);
		glAttachShader(m_shaderProgramHandle, m_fragmentShaderHandle);
		// Link the shaders
		glLinkProgram(m_shaderProgramHandle);
		this->checkOnErrors(m_shaderProgramHandle, "PROGRAM");
		return true;
	}
	catch (char const *e) {
		std::cerr << e << std::endl;
		return false;
	}
}

void ShaderBuilder::deleteShaders()
{
	// Delete the shaders as they're linked into our program now and no longer necessery
	glDeleteShader(m_vertexShaderHandle);
	glDeleteShader(m_fragmentShaderHandle);
}

bool ShaderBuilder::build(VertexShader &&vert, FragmentShader &&frag) noexcept
{
	if (!this->compile(vert.getCode().c_str(), frag.getCode().c_str()) || !this->link()) {
		return false;
	}
	this->deleteShaders();
	return true;
}

void ShaderBuilder::run()
{
	glUseProgram(m_shaderProgramHandle);
}

} // namespace Graphics

} // namespace mlg
