#pragma once
#include "AbsObject.h"

class Triangle : public AbsObject
{
private:
	GLuint VBO = 0;
	
public:
	int DrawBy = 3;
	GLuint VAO=0;
	int GetDrawBy() { return this->DrawBy; };
	void bindVertexArray() { glBindVertexArray(this->VAO); };
	Triangle(Shader *sh);
	
};

