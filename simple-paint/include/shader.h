#pragma once 

#include <string>

namespace mlg
{

namespace Graphics
{

class Shader
{
public:
	explicit Shader(std::string&& path);
    virtual ~Shader() noexcept = default;
	virtual std::string&& getCode() noexcept = 0;
protected:
	std::string m_code;
};

class VertexShader : public Shader
{
public:
	explicit VertexShader(std::string&& path) noexcept;
    ~VertexShader() noexcept override = default;
	std::string&& getCode() noexcept override;
};

class FragmentShader : public Shader
{
public:
	explicit FragmentShader(std::string&& path) noexcept;
    ~FragmentShader() noexcept override = default;
	std::string&& getCode() noexcept override;
};

} // namespace Graphics

} // namespace mlg
