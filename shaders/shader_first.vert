#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
uniform mat4 m_projection;
uniform mat4 m_view;
uniform mat4 m_model;

void main()
{
	vec4 v = vec4(vertexPosition_modelspace, 1);
	gl_Position = m_projection * m_view * m_model * v;
}
