#version 420

layout(location = 0) in vec2 inUV;

out vec4 frag_color;

layout (binding = 0) uniform sampler2D s_screenTex0;
layout (binding = 1) uniform sampler2D s_screenTex1;
layout (binding = 2) uniform sampler2D s_screenTex2;
layout (binding = 3) uniform sampler2D s_screenTex3;
layout (binding = 4) uniform sampler2D s_screenTex4;


void main() 
{
	vec4 source = texture(s_screenTex0, inUV);


	frag_color.r = source.r;
	frag_color.g = source.b;
	frag_color.b = source.g;
    frag_color.a = source.a;
}