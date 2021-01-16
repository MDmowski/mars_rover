#version 330 core
in vec3 vecColor;
in vec2 TexCoord;

uniform vec3 lightColor;

out vec4 color;


void main()
{
    color = vec4(vecColor * lightColor, 1.0);
}
