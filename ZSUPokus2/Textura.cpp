#include "Textura.h"

Textura::Textura(const char* path,int tu)
{
	
	glActiveTexture(GL_TEXTURE0 + tu);
	textureID = SOIL_load_OGL_texture(path, SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	glBindTexture(GL_TEXTURE_2D, textureID);
	texture_unit_id = tu;
	this->path = path;

}

Textura::Textura()
{
}

