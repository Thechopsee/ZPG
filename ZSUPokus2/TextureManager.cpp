#include "TextureManager.h"

TextureManager::TextureManager()
{
}

Textura* TextureManager::findByName(const char* texture_path)
{
	for (Textura* a : Textury)
	{
		if (strcmp(a->getName(), texture_path) == 0)
		{
			return a;
		}
	}
}

Textura* TextureManager::prepareNewTexture(const char* texture_path)
{
	Textura* tx = new Textura(texture_path, textureunit);
	textureunit++;
	Textury.push_back(tx);
	return tx;
}

Textura* TextureManager::prepareNewTexture(const char* pathx, const char* pathy, const char* pathz, const char* pathnx, const char* pathny, const char* pathnz)
{
	Cubemap* cm = new Cubemap(pathx, pathy, pathz, pathnx, pathny, pathnz, textureunit);
	textureunit++;
	Textury.push_back(cm);
	return cm;
}
