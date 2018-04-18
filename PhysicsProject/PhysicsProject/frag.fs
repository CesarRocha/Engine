#version 330 core

//Uniforms
uniform sampler2D gDiffuseMap;

//Passed in
in vec2 passUV;
in vec4 passColor;

//Output
out vec4 pixelColor;


void main()
{
	pixelColor = passColor;
	pixelColor = texture(gDiffuseMap, passUV);
}

