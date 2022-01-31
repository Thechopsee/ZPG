#include "Cubemap.h"

Cubemap::Cubemap(const char* pathx, const char* pathy, const char* pathz, const char* pathnx, const char* pathny, const char* pathnz, int tu)
{
	glActiveTexture(GL_TEXTURE0 + tu);
	textureID = SOIL_load_OGL_cubemap(pathx, pathnx, pathy, pathny, pathz, pathnz, SOIL_LOAD_RGB, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);
	if (textureID == 0)
	{
		exit(0);
	}
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
	texture_unit_id = tu;
	this->path = pathx;
}

void Cubemap::specialThingforRender(bool prom)
{
	if (prom)
	{
		glDepthMask(GL_TRUE);
	}
	else
	{
		glDepthMask(GL_FALSE);
	}
}

bool Cubemap::imCube()
{
	return true;
}
