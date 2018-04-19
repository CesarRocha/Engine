#version 330 core

//Uniforms
uniform sampler2D gDiffuseMap;
uniform vec4 gAmbientColor;

//Passed in
in vec2 passUV;
in vec4 passColor;

//Output
out vec4 pixelColor;


void main()
{
	pixelColor = passColor;
}

