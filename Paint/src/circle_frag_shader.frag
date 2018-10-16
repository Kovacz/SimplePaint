#version 330 core

uniform vec2 viewDimensions;
uniform float outerRadius;

out vec4 outColor;

void main(void)
{
    gl_FragCoord = vec4(0.5f, -0.5f, 0.f, 1.f);
    float x = (gl_FragCoord.x - viewDimensions.x / 2.f) / (viewDimensions.x / 2.f);
    float y = (gl_FragCoord.y - viewDimensions.y / 2.f) / (viewDimensions.y / 2.f);
    float len = sqrt(x*x + y*y);

    if (len > outerRadius)
        discard;
    outColor = vec4(0.f, 0.f, 0.f, 1.f);
}
