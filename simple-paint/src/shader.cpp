#include "shader.h"
#include <iostream>
#include <fstream>
#include <sstream>

namespace mlg
{

namespace Graphics
{

VertexShader::VertexShader(std::string&& path)
{
    std::ifstream shaderFile;
    // ensure ifstream objects can throw exceptions:
    shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try{
        // open files
        shaderFile.open(path);
        std::stringstream shaderStream;
        // read file's buffer contents into streams
        shaderStream << shaderFile.rdbuf();
        // close file handlers
        shaderFile.close();
        // save shaders
        m_code = shaderStream.str();
    }
    catch (std::ifstream::failure e) {
        std::cerr << "ERROR::VERTEX_SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
}

std::string&& VertexShader::getCode() noexcept
{
    return std::move(m_code);
}

FragmentShader::FragmentShader(std::string&& path)
{
    std::ifstream shaderFile;
    // ensure ifstream objects can throw exceptions:
    shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try{
        // open files
        shaderFile.open(path);
        std::stringstream shaderStream;
        // read file's buffer contents into streams
        shaderStream << shaderFile.rdbuf();
        // close file handlers
        shaderFile.close();
        // save shaders
        m_code = shaderStream.str();
    }
    catch (std::ifstream::failure e) {
        std::cerr << "ERROR::FRAGMENT_SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
}

std::string&& FragmentShader::getCode() noexcept
{
    return std::move(m_code);
}


} // namespace Graphics

} // namespace mlg
