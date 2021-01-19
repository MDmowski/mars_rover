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
    // perform perspective divide
    vec3 projCoords = fragmentPos.xyz / fragmentPos.w;

    if(projCoords.z > 1.0)
        return 0.0f;
    // transform to [0,1] range
    projCoords = projCoords * 0.5 + 0.5;
    // get closest depth value from light's perspective (using [0,1] range fragPosLight as coords)
    float closestDepth = texture(shadowMap, projCoords.xy).r; 
    // get depth of current fragment from light's perspective
    float currentDepth = projCoords.z;
    // check whether current frag pos is in shadow
    float bias =  max(0.05 * (1.0 - dot(normal, lightDirection)), 0.005); 
    float shadow = 0.0;
    vec2 texelSize = 1.0 / textureSize(shadowMap, 0);
    for(int x = -1; x <= 1; ++x)
    {
        for(int y = -1; y <= 1; ++y)
        {
            float pcfDepth = texture(shadowMap, projCoords.xy + vec2(x, y) * texelSize).r; 
            shadow += currentDepth - bias > pcfDepth  ? 1.0 : 0.0;        
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
