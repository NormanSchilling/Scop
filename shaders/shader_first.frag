#version 330 core

in vec2 UV;
// in int checkRenderMode;

out vec3 color;

uniform int renderMode;
uniform sampler2D myTextureSampler;

void main()
{
	if (renderMode == 0)
		color = vec3(1,0,0);
	else
		color = texture( myTextureSampler, UV ).rgb;

}
