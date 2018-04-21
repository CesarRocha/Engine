#version 330 core

//Uniforms
uniform vec4 gLightColor;

//Output
out vec4 pixelColor;


void main()
{
	pixelColor = gLightColor;
}

