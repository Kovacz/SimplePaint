#pragma once 

#include <string>

namespace mlg
{

namespace Graphics
{

class VertexShader 
{
public:
    VertexShader(std::string&& path);
    ~VertexShader() noexcept = default;
    std::string&& getCode() noexcept; 
private:
    std::string m_code;
};

class FragmentShader 
{
public:
    FragmentShader(std::string&& path);
    ~FragmentShader() noexcept = default;
    std::string&& getCode() noexcept; 
private:
    std::string m_code;
};

} // namespace Graphics

} // namespace mlg
