#include "Shader.h"
#include <cstdio>


Shader::Shader(const char* vertex, const char* fragment)
{
	this->loadShader(vertex,fragment);
}

void Shader::checkError()
{
	GLint status;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(shaderProgram, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Linker failure: %s\n", strInfoLog);
		delete[] strInfoLog;
	}
}

void Shader::useShader()
{
	glUseProgram(this->shaderProgram);
}

void Shader::setMa4(glm::mat4 matrix, const char* adress)
{
	GLint idModelTransform = glGetUniformLocation(this->shaderProgram, adress);
	glUniformMatrix4fv(idModelTransform, 1, GL_FALSE, &matrix[0][0]);
}

void Shader::setVec3(glm::vec3 vecto,const char * adress)
{
	GLint idModelTransform = glGetUniformLocation(this->shaderProgram, adress);
	glUniform3fv(idModelTransform, 1, &vecto[0]);
}
void Shader::setVec4(glm::vec4 vecto, const char* adress)
{
	GLint idModelTransform = glGetUniformLocation(this->shaderProgram, adress);
	glUniform4fv(idModelTransform, 1, &vecto[0]);
}
void Shader::setBool(bool neco, const char* adress)
{
	GLint idModelTransform = glGetUniformLocation(this->shaderProgram, adress);
	glUniform1i(idModelTransform,neco);
}
void Shader::setFloat(float neco, const char* adress)
{
	GLint idModelTransform = glGetUniformLocation(this->shaderProgram, adress);
	glUniform1f(idModelTransform, neco);
}