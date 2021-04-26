#pragma once

#include "Graphics/Post/PostEffect.h"

class NightVision : public PostEffect
{
public:
	//Initializes framebuffer
	//Overrides post effect Init
	void Init(unsigned width, unsigned height) override;

	//Applies the effect to this buffer
	//passes the previous framebuffer with the texture to apply as parameter
	void ApplyEffect(PostEffect* buffer) override;

	//Getters

	float myTime = 0.0f;
	Texture2D::sptr noiseText;
	//Setters

private:

};