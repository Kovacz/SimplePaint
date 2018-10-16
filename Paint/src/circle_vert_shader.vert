#version 330 core

in vec2 pos;

void main(void)
{
    gl_Position = vec4(pos, 0.f, 1.f);
}
