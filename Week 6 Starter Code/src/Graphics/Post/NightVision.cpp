#include "NightVision.h"

void NightVision::Init(unsigned width, unsigned height)
{
    int index = int(_buffers.size());
    _buffers.push_back(new Framebuffer());
    _buffers[index]->AddColorTarget(GL_RGBA8);
    _buffers[index]->AddDepthTarget();
    _buffers[index]->Init(width, height);

    index = int(_shaders.size());
    _shaders.push_back(Shader::Create());
    _shaders[index]->LoadShaderPartFromFile("shaders/passthrough_vert.glsl", GL_VERTEX_SHADER);
    _shaders[index]->LoadShaderPartFromFile("shaders/Post/nightvision_frag.glsl", GL_FRAGMENT_SHADER);
    _shaders[index]->Link();

   
    noiseText = Texture2D::LoadFromFile("images/noise.jpg");

}

void NightVision::ApplyEffect(PostEffect* buffer)
{
    BindShader(0);
    _shaders[0]->SetUniform("elapsedTime", myTime);
    
    buffer->BindColorAsTexture(0, 0, 0);
    noiseText->Bind(1);

    _buffers[0]->RenderToFSQ();

    buffer->UnbindTexture(0);

    UnbindShader();

}
