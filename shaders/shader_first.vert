#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 normal;

out vec2 UV;
out vec3 normalFrag;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main()
{
	vec4 v = vec4(vertexPosition_modelspace, 1);
	gl_Position = projection * view * model * v;
	UV = vertexPosition_modelspace.xy;
	normalFrag = (model * vec4(normal, 1)).xyz;
}
