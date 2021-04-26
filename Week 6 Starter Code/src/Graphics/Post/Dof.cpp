#include "Dof.h"


void Dof::Init(unsigned width, unsigned height)
{
    int index = int(_buffers.size());
    _buffers.push_back(new Framebuffer());
    _buffers[index]->AddColorTarget(GL_RGBA8);
    _buffers[index]->AddDepthTarget();
    _buffers[index]->Init(width, height);

    //Loads the shaders
    index = int(_shaders.size());
    _shaders.push_back(Shader::Create());
    _shaders[index]->LoadShaderPartFromFile("shaders/passthrough_vert.glsl", GL_VERTEX_SHADER);
    _shaders[index]->LoadShaderPartFromFile("shaders/Post/dof_frag.glsl", GL_FRAGMENT_SHADER);
    _shaders[index]->Link();
}

void Dof::ApplyEffect(PostEffect* buffer)
{
    BindShader(0);

    buffer->BindColorAsTexture(0, 0, 0);

    _buffers[0]->RenderToFSQ();

    buffer->UnbindTexture(0);

    UnbindShader();
}

void Dof::ApplyEffect(GBuffer* gBuffer)
{
    BindShader(0);
    _shaders[0]->SetUniform("zNear", zNear);
    _shaders[0]->SetUniform("zFar", zFar);
    _shaders[0]->SetUniform("planeInFocus", planeInFocus);
    _shaders[0]->SetUniform("focalLength", focalLength);
    _shaders[0]->SetUniform("aperture", aperture);
    gBuffer->bindDepth();

    _buffers[0]->RenderToFSQ();

    gBuffer->unBindDepth();

    UnbindShader();
}

