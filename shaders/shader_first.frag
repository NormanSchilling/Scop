#version 330 core

in vec2 UV;
in vec3 normalFrag;

out vec3 color;

uniform int renderMode;
uniform sampler2D myTextureSampler;

void main()
{
	if (renderMode == 0)
	{
		// color = vec3(0.2,0.5,0.5);
		color = normalFrag;
	}
	else
		color = texture( myTextureSampler, UV ).rgb;
}
