#version 330 core
in vec3 vecColor;
in vec2 TexCoord;
in vec3 Normal;
in vec3 FragmentPosition;

struct DirectionalLight {
    vec3 direction;

    vec3 ambience;
    vec3 diffusion;
    vec3 specularity;
};


uniform DirectionalLight sun;
uniform vec3 viewPosition;


out vec4 color;

vec3 CalculateDirectionalLight(DirectionalLight light, vec3 normal, vec3 viewDirection){
    // reverse direction because we expect user to pass us vector from light
    vec3 lightDirection = normalize(-light.direction);

    float diffusionCoef = max(dot(normal, lightDirection), 0.0);

	float specularityCoef = 0.0f;

    if(diffusionCoef > 0.0f)
		specularityCoef = pow(max(dot(viewDirection, reflect(-lightDirection, normal)), 0.0), 32);

     vec3 diffusion = diffusionCoef * light.diffusion;
     vec3 specularity = specularityCoef * light.specularity;

    return (specularity + diffusion +  light.ambience);
}

void main()
{

    vec3 viewDirection = normalize(viewPosition - FragmentPosition);

    color = vec4(vecColor * CalculateDirectionalLight(sun, Normal, viewDirection), 1.0);
}
