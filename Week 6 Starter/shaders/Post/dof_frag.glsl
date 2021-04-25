#version 420

layout(location = 0) in vec2 inUV;

out vec4 frag_color;

layout (binding = 0) uniform sampler2D s_screenTex;


uniform float zNear = 1.0f;
uniform float zFar = 4.0f;
uniform float planeInFocus = 3.0f;
uniform float focalLength = 0.0303f;
uniform float aperture = 0.6062f;

float calculateScale(){
	return (aperture * focalLength * planeInFocus *(zFar - zNear))/((planeInFocus * focalLength)*zNear);
}

float calculateBias(){
	return (aperture * focalLength * (zNear - planeInFocus))/ ((planeInFocus * focalLength) * zNear);
}

void main() 
{
	vec4 source = texture(s_screenTex, inUV);

	float dist = source.r;

	float coc = abs(dist * calculateScale() + calculateBias());

	frag_color.r = coc;
	frag_color.g = coc;
	frag_color.b = coc;
    frag_color.a = source.a;
}