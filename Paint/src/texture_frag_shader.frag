#version 330 core
in vec4 TexPos;
in vec3 ourColor;
in vec2 TexCoord;

out vec4 color;

uniform sampler2D ourTexture;

uniform vec2 viewDimensions;
uniform float outerRadius;

void main()
{
    color = texture(ourTexture, TexCoord);
    //color = vec4(ourColor, 1.f);
}