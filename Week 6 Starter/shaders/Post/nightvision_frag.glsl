//https://tobiasbu.wordpress.com/2016/01/16/opengl-night-vision-shader/
#version 420

layout(location = 0) in vec2 inUV;

out vec4 frag_color;

layout (binding = 0) uniform sampler2D s_screenTex;
layout (binding = 1) uniform sampler2D noiseTexture;

uniform float elapsedTime;

float contrast = 0.5;

void main() 
{
	vec2 uv;
	uv.x = 0.35*sin(elapsedTime*50.0);
	uv.y = 0.35*cos(elapsedTime*50.0);  

	vec3 noise = texture(noiseTexture, inUV.st + uv).rgb;

	vec3 sceneColor = texture(s_screenTex, inUV.st + (noise.xy*0.005)).rgb;

	const vec3 lumvec = vec3(0.30, 0.59, 0.11);

	float intentisy = dot(lumvec,sceneColor) ;

	intentisy = clamp(contrast * (intentisy - 0.5) + 0.5, 0.0, 1.0);
	float green = clamp(intentisy / 0.59, 0.0, 1.0);

	vec3 visionColor = vec3(0,green,0);

	frag_color = vec4((sceneColor + (noise*0.2)) * visionColor,1.0);

}