#pragma once

#include <GL/glew.h>
#include <SOIL/SOIL.h>

class Textura
{
protected:
	GLuint textureID = 0;
	int texture_unit_id;
	const char* path;
public:
	Textura();
	Textura(const char * path,int tu);
	int returnTUI() 
	{
		return this->texture_unit_id;
	}
	const char* getName()
	{
		return path;
	}
	GLuint getTextureId() 
	{
		return this->textureID;
	};
	void useTexture(GLuint shaderProgram)
	{
		GLint uniformID = glGetUniformLocation(shaderProgram, "textureUnitID");
		glUniform1i(uniformID, this->texture_unit_id);
	}
	void useMeLikeNormalMap(GLuint shaderProgram)
	{
		GLint uniformID = glGetUniformLocation(shaderProgram, "UINormal");
		glUniform1i(uniformID, this->texture_unit_id);
	}
	virtual void specialThingforRender(bool prom)
	{
		return;
	}
	virtual bool imCube()
	{
		return false;
	}
};

