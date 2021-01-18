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

	vec3 specularityPart = vec3(0, 0, 0);
    if(diffusionCoef > 0.0f)
		specularityPart = pow(max(dot(viewDirection, reflect(-lightDirection, normal)), 0.0), 2) * light.specularity;

     vec3 diffusion = diffusionCoef * light.diffusion;

    return ( specularityPart + diffusion +  light.ambience);
    //return ( specularityPart + light.ambience);
    //return (specularityPart);
}

void main()
{
    //float ambientIntensity = 0.2;

    //vec3 ambient = ambientIntensity * lightColor;

    //vec3 lightDirection = normalize(lightPos - FragmentPosition);
    //float diffuseIntensity = max(dot(Normal, lightDirection), 0.0);

    //vec3 diffuse = diffuseIntensity * lightColor;

    //vec3 resultingColor = vecColor * (ambient + diffuse);

    vec3 viewDirection = normalize(viewPosition - FragmentPosition);

    color = vec4(vecColor * CalculateDirectionalLight(sun, Normal, viewDirection), 1.0);
}
