#pragma once

#include <vector>
#include "Textura.h"
#include "Cubemap.h"

class TextureManager
{
private:
	std::vector<GLuint> texture;
	std::vector<Textura*> Textury;
	int textureunit = 0;
public:

	TextureManager();

	Textura* findByName(const char* texture_path);
	Textura* prepareNewTexture(const char* texture_path);
	Textura* prepareNewTexture(const char* pathx, const char* pathy, const char* pathz, const char* pathnx, const char* pathny, const char* pathnz);
	
	
};

