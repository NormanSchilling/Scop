#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;

out vec2 UV;
// out	int	checkRenderMode;

// uniform int renderMode;
uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main()
{
	vec4 v = vec4(vertexPosition_modelspace, 1);
	gl_Position = projection * view * model * v;
	UV = vertexPosition_modelspace.xy;
	// checkRenderMode = renderMode;
}
