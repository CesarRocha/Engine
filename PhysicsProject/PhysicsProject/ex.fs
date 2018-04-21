#version 330 core

//Uniforms
uniform vec3 gCameraPos;

//Material
struct Materials {
	sampler2D m_diffuseMap;
	sampler2D m_specularMap;
    int   m_shininess;
};uniform Materials gMaterial;

//Light
struct Light {
    vec3 m_position;
    vec3 m_ambient;
    vec3 m_diffuse;
    vec3 m_specular;
};uniform Light gLight;


//Passed in
in vec3 passPos;
in vec2 passUV;
in vec4 passColor;
in vec3 passNormal;

//Output
out vec4 pixelColor;


void main()
{
//Textures
	vec4 diffuseTexel  = texture(gMaterial.m_diffuseMap, passUV);
	vec4 specularTexel = texture(gMaterial.m_specularMap, passUV);

//Diffuse 
    vec3 norm = normalize(passNormal);
    vec3 lightDir = normalize(gLight.m_position - passPos);
    float diff = max(dot(norm, lightDir), 0.0);

//Specular
    vec3 viewDir = normalize(gCameraPos - passPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), gMaterial.m_shininess);
	
//Totals
    vec3 ambient  = gLight.m_ambient  * diffuseTexel.rgb;
    vec3 diffuse  = gLight.m_diffuse  * diff * diffuseTexel.rgb;
    vec3 specular = gLight.m_specular * spec * specularTexel.rgb ;  
        
	vec3 final = ambient + diffuse + specular;
    pixelColor = vec4(final, 1.0);
}
