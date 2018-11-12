#pragma once 

#include "window.h"
#include "camera.h"
#include "texture.h"
#include "shaderbuilder.h"

namespace mlg
{

namespace Graphics
{

class Scene 
{
public:
	Scene();
	~Scene() noexcept;
	explicit operator bool() const noexcept;
    // delete unused functionality
    Scene(Scene&&) = delete;
    Scene(Scene const&) = delete;
    Scene& operator=(Scene const&) = delete;
    // TODO: drawing and updating here?
	void onDraw();
	void onUpdate();
    // TODO: make sure about all noexcept here
	bool load() noexcept;
	void display() const noexcept;
	void setBgColor(float const& r, float const& g, float const& b, float const& a) const noexcept;
public:
    // smoothly creating
	static Scene make_scene();
private:  
	// "self use" only
	void gladInit() const;
private: 
    // {camera, shader, texture, window, primitive}
	Graphics::Camera m_camera;
	Graphics::ShaderBuilder m_shaderProgram;
	Graphics::Texture* m_pTexture {nullptr};
	System::Window*    m_pWindow  {nullptr};
};

} // namespace Graphics

} // namespace mlg
