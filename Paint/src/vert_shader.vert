#version 330 core

layout (location = 0) in vec2 aPos;

void main(void)
{
    gl_Position = vec4(aPos.x, aPos.y, 0.f, 1.f);
}
