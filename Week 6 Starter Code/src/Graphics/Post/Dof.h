#pragma once

#include "Graphics/Post/PostEffect.h"
#include "Graphics/GBuffer.h"
class Dof : public PostEffect
{
public:
	//Initializes framebuffer
	//Overrides post effect Init
	void Init(unsigned width, unsigned height) override;

	//Applies the effect to this buffer
	//passes the previous framebuffer with the texture to apply as parameter
	void ApplyEffect(PostEffect* buffer) override;
	void ApplyEffect(GBuffer* gBuffer);

	//Getters

	//Setters

	float zNear = 1.0f;
	float zFar = 2.8f;
	float planeInFocus = 12.0f;
	float focalLength = 0.0303f;
	float aperture = 0.6062f;
private:

};