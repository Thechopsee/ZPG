#include "ShaderFactory.h"

Shader* ShaderFactory::makeShader(ShaderEnum shader_type)
{
	switch (shader_type)
	{
	case KONSTANTNI:
		return new Shader("Constant.vs", "Constant.fs");
	case LAMBERT:
		return new Shader("lambert.vs", "lambert.fs");
	case PHONG:
		return new Shader("Phong.vs", "new_spot.fs");
	case TEXTURED:
		return new Shader("texture.vs", "texture.fs");
	case TEX_CUBE:
		return new Shader("texture.vs", "sky2.fs");
	case TEX_SKY:
		return new Shader("texture_cube.vs", "texture_cube.fs");
	case NEW_PHONG:
		return new Shader("new_phong.vs", "new_phong.fs");
	case FINAL_PHONG:
		return new Shader("final_phong.vs", "final_phong.fs");
	}
}
