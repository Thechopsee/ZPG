#pragma once
#include "Shader.h"
enum ShaderEnum
{
	KONSTANTNI,
	LAMBERT,
	PHONG,
	TEXTURED,
	TEX_SKY,
	TEX_CUBE,
	NEW_PHONG,
	FINAL_PHONG
};
class ShaderFactory
{
public:
	static Shader* makeShader(ShaderEnum shader_type);
	
};

