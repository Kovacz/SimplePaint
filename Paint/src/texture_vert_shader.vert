#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 texCoord;

out vec3 ourColor;
out vec2 TexCoord;

//uniform vec2 scale;
uniform mat4 model;
//uniform mat4 view;
//uniform mat4 projection;

void main()
{
    gl_Position = model * vec4(position, 1.0f);
    //gl_Position = vec4(position, 1.0f);
	//gl_Position = vec4(position.x * scale.x, position.y * scale.y, 0.f, 1.f);
    ourColor = color;
    TexCoord = texCoord;
}