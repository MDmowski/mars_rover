#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 texCoord;
layout (location = 3) in vec3 normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 lightSpaceMatrix;

out vec3 vecColor;
out vec2 TexCoord;
out vec3 Normal;
out vec3 FragmentPosition;
out vec4 FragmentPositionLightSpace;


void main()
{
    // Pass variables to the fragment shader w/o changing
    vecColor = color;

    Normal = normalize(mat3(transpose(inverse(model))) * normal);

    // Transform vertex position to world space coordinates
    FragmentPosition = vec3(model * vec4(position, 1.0));
    FragmentPositionLightSpace = lightSpaceMatrix * vec4(FragmentPosition, 1.0);

    gl_Position = projection * view * model * vec4(position, 1.0f);
    TexCoord = vec2(texCoord.x, 1.0 - texCoord.y);
} 