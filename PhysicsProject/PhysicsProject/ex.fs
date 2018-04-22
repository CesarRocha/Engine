#version 330 core
//Output
out vec4 pixelColor;


//Uniforms
uniform vec3 gCameraPos;



//Material
struct Materials {
	sampler2D m_diffuseMap;
	sampler2D m_specularMap;
    int   m_shininess;
};uniform Materials gMaterial;



//Lights
struct DirectionalLight {
    vec3 direction;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};  
#define MAX_NUM_DIRECTIONAL_LIGHTS 16
uniform DirectionalLight gDirectionalLight[MAX_NUM_DIRECTIONAL_LIGHTS];
uniform int gNumDirectionalLights;


struct PointLight {    
    vec3  position;
    
    float constant;
    float linear;
    float quadratic;  

    vec3  ambient;
    vec3  diffuse;
    vec3  specular;
}; 
#define MAX_NUM_POINT_LIGHTS 16
uniform PointLight gPointLight[MAX_NUM_POINT_LIGHTS];
uniform int gNumPointLights;


struct SpotLight {
    vec3  position;
    vec3  direction;
    float cutoff;
    float outerCutoff;
  
    float constant;
    float linear;
    float quadratic;
  
    vec3  ambient;
    vec3  diffuse;
    vec3  specular;       
}; 
#define MAX_NUM_SPOT_LIGHTS 16
uniform SpotLight gSpotLight[MAX_NUM_SPOT_LIGHTS];
uniform int gNumSpotLights;



//Passed in
in vec3 passPos;
in vec2 passUV;
in vec4 passColor;
in vec3 passNormal;


vec3 CalculateDirectionalLights(DirectionalLight lights, vec3 normal, vec3 viewDirection);
vec3 CalculatePointLights(PointLight lights, vec3 normal, vec3 passPos, vec3 viewDirection);
vec3 CalculateSpotLights(SpotLight lights, vec3 normal, vec3 passPos, vec3 viewDirection);
void main()
{

	vec3 final_color = vec3(0.0);
	vec3 norm = normalize(passNormal);
    vec3 viewDir = normalize(gCameraPos - passPos);
	
	for(int i = 0; i < gNumDirectionalLights; i++)
  		final_color += CalculateDirectionalLights(gDirectionalLight[i], norm, viewDir);
	
	for(int i = 0; i < gNumPointLights; i++)
		final_color += CalculatePointLights(gPointLight[i], norm, passPos, viewDir);
	
	for(int i = 0; i < gNumSpotLights; i++)
		final_color += CalculateSpotLights(gSpotLight[i], norm, passPos, viewDir);

    pixelColor = vec4(final_color, 1.0);
}
//==========================================================================================














//==========================================================================================
vec3 CalculateDirectionalLights(DirectionalLight light, vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(-light.direction);

    float diff = max(dot(normal, lightDir), 0.0);

    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), gMaterial.m_shininess);

    vec3 ambient  = light.ambient  *  1.0 * vec3(texture(gMaterial.m_diffuseMap, passUV));
    vec3 diffuse  = light.diffuse  * diff * vec3(texture(gMaterial.m_diffuseMap, passUV));
    vec3 specular = light.specular * spec * vec3(texture(gMaterial.m_specularMap, passUV));
    return (ambient + diffuse + specular);
}
//==========================================================================================
vec3 CalculatePointLights(PointLight light, vec3 normal, vec3 passPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - passPos);

    float diff = max(dot(normal, lightDir), 0.0);

    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), gMaterial.m_shininess);

    float distance = length(light.position - passPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    

    vec3 ambient  = light.ambient  *  1.0 * vec3(texture(gMaterial.m_diffuseMap, passUV));
    vec3 diffuse  = light.diffuse  * diff * vec3(texture(gMaterial.m_diffuseMap, passUV));
    vec3 specular = light.specular * spec * vec3(texture(gMaterial.m_specularMap, passUV));
   
    ambient  *= attenuation;
    diffuse  *= attenuation;
    specular *= attenuation;

    return (ambient + diffuse + specular);
}

//==========================================================================================
vec3 CalculateSpotLights(SpotLight light, vec3 normal, vec3 passPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - passPos);

    float diff = max(dot(normal, lightDir), 0.0);

    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), gMaterial.m_shininess);

    float distance = length(light.position - passPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    

    float theta		= dot(lightDir, normalize(-light.direction)); 
    float epsilon	= light.cutoff - light.outerCutoff;
    float intensity = clamp((theta - light.outerCutoff) / epsilon, 0.0, 1.0);

    vec3 ambient	= light.ambient  *  1.0 * vec3(texture(gMaterial.m_diffuseMap, passUV));
    vec3 diffuse	= light.diffuse  * diff * vec3(texture(gMaterial.m_diffuseMap, passUV));
    vec3 specular	= light.specular * spec * vec3(texture(gMaterial.m_specularMap, passUV));

    ambient  *= attenuation * intensity;
    diffuse  *= attenuation * intensity;
    specular *= attenuation * intensity;
  
    return (ambient + diffuse + specular);
}