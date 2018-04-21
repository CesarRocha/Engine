#version 330 core

uniform mat4 gModel;
uniform mat4 gView;
uniform mat4 gProj;


//Input
in vec3 inPos;


void main()
{
	gl_Position = gProj * gView * gModel * vec4(inPos.x, inPos.y, inPos.z, 1.0);
}