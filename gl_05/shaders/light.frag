#version 330 core
in vec3 vecColor;
in vec2 TexCoord;
in vec3 Normal;
in vec3 FragmentPosition;
in vec4 FragmentPositionLightSpace;

struct DirectionalLight {
    vec3 direction;

    vec3 ambience;
    vec3 diffusion;
    vec3 specularity;
};


uniform DirectionalLight sun;
uniform vec3 viewPosition;
uniform sampler2D shadowMap;
uniform sampler2D Texture0;

out vec4 color;

float CalculateShadow(vec4 fragmentPos, vec3 normal, vec3 lightDirection){
    // transform to normalized coordinates
    vec3 projCoords = fragmentPos.xyz / fragmentPos.w;

    // fix shadows beyond projection
    if(projCoords.z > 1.0)
        return 0.0f;

    // transform cords to be in range from 0 to 1 inclusive
    projCoords = projCoords * 0.5 + 0.5;

    // closest depth from light's perspective
    float closestDepth = texture(shadowMap, projCoords.xy).r; 

    float currentDepth = projCoords.z;

    // calculate bias based on lightDirection
    float bias =  max(0.05 * (1.0 - dot(normal, lightDirection)), 0.005); 

    // reduce blocky shadows by performing sampling around current pixel
    float shadow = 0.0;
    vec2 texelSize = 1.0 / textureSize(shadowMap, 0);
    for(int x = -1; x <= 1; ++x)
    {
        for(int y = -1; y <= 1; ++y)
        {
            float depth = texture(shadowMap, projCoords.xy + vec2(x, y) * texelSize).r; 
            shadow += currentDepth - bias > depth  ? 1.0 : 0.0;        
        }    
    }

    // nine samples takes so we have to avarage
    shadow /= 9.0;

    return shadow;
}

vec3 CalculateDirectionalLight(DirectionalLight light, vec3 normal, vec3 viewDirection){
    // reverse direction because we expect user to pass us vector from light
    vec3 lightDirection = normalize(-light.direction);

    float diffusionCoef = max(dot(normal, lightDirection), 0.0);

	float specularityCoef = 0.0f;

    if(diffusionCoef > 0.0f)
		specularityCoef = pow(max(dot(viewDirection, reflect(-lightDirection, normal)), 0.0), 32);

     vec3 diffusion = diffusionCoef * light.diffusion;
     vec3 specularity = specularityCoef * light.specularity;
     float shadow = CalculateShadow(FragmentPositionLightSpace, normal, lightDirection);

    return ((specularity + diffusion) * (1.0f - shadow) +  light.ambience);
}

void main()
{

    vec3 viewDirection = normalize(viewPosition - FragmentPosition);

    color = vec4(vecColor * CalculateDirectionalLight(sun, Normal, viewDirection), 1.0) * texture(Texture0, TexCoord);
}
