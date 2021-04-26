#version 420

layout(location = 0) in vec2 inUV;

layout (location = 0) out vec4 FragColor;
layout (location = 1) out vec4 BrightColor;

layout (binding = 0) uniform sampler2D s_screenTex;


void main()
{            

    BrightColor = texture(s_screenTex,inUV);
    
    float brightness = dot(BrightColor.rgb, vec3(0.2126, 0.7152, 0.0722));
    if(brightness > 0.75)
        FragColor = vec4(BrightColor.rgb, 1.0);
    else
        FragColor = vec4(0.0, 0.0, 0.0, 1.0);
}