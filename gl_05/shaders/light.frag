#version 330 core
in vec3 vecColor;
in vec2 TexCoord;
in vec3 Normal;
in vec3 FragmentPosition;

uniform vec3 lightColor;
uniform vec3 lightPos;

out vec4 color;


void main()
{
    float ambientIntensity = 0.2;

    vec3 ambient = ambientIntensity * lightColor;

    vec3 lightDirection = normalize(lightPos - FragmentPosition);
    float diffuseIntensity = max(dot(Normal, lightDirection), 0.0);

    vec3 diffuse = diffuseIntensity * lightColor;

    vec3 resultingColor = vecColor * (ambient + diffuse);

    color = vec4(resultingColor, 1.0);
}
