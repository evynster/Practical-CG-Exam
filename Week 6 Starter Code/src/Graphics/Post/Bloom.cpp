#include "Bloom.h"

void Bloom::Init(unsigned width, unsigned height)
{
    int index = int(_buffers.size());
    _buffers.push_back(new Framebuffer());
    _buffers[index]->AddColorTarget(GL_RGBA8);
    _buffers[index]->AddColorTarget(GL_RGBA8);
    _buffers[index]->AddDepthTarget();
    _buffers[index]->Init(width, height);


    //Loads the shaders
    index = int(_shaders.size());
    _shaders.push_back(Shader::Create());
    _shaders[index]->LoadShaderPartFromFile("shaders/passthrough_vert.glsl", GL_VERTEX_SHADER);
    _shaders[index]->LoadShaderPartFromFile("shaders/Post/bloom_frag.glsl", GL_FRAGMENT_SHADER);
    _shaders[index]->Link();

    index = int(_shaders.size());
    _shaders.push_back(Shader::Create());
    _shaders[index]->LoadShaderPartFromFile("shaders/passthrough_vert.glsl", GL_VERTEX_SHADER);
    _shaders[index]->LoadShaderPartFromFile("shaders/Post/bloom_blur_frag.glsl", GL_FRAGMENT_SHADER);
    _shaders[index]->Link();
}

void Bloom::ApplyEffect(PostEffect* buffer)
{
    BindShader(0);

    buffer->BindColorAsTexture(0, 0, 0);
    buffer->BindColorAsTexture(1, 0, 1);

    _buffers[0]->RenderToFSQ();

    buffer->UnbindTexture(0);
    buffer->UnbindTexture(1);

    UnbindShader();

}
