#pragma once
#include "BufferCPU.h"
#include "TextureGPU.h"
#include "Demo.h"

// forward declaration
class Demo;

class Texture
{
public:
	int width;
	int height;

	// Texture data
	BufferCPU* textureCPU;
	TextureGPU* textureGPU;

	Texture(char* file, Demo* demo);
	~Texture();
};

