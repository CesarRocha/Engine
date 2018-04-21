#version 330 core

uniform mat4 gModel;
uniform mat4 gView;
uniform mat4 gProj;



//Input
in vec3 inPos;
in vec2 inUV;
in vec4 inColor; 
in vec3 inNormal;


//ToPass
out vec3 passPos;
out vec2 passUV;
out vec4 passColor;
out vec3 passNormal;


void main()
{
	gl_Position = gProj * gView * gModel * vec4(inPos.x, inPos.y, inPos.z, 1.0);
	
	//passPos = vec3(gModel * vec4(inPos, 1.0));
	//passUV = inUV;
	//passColor = inColor;
	//passNormal = inNormal;
}