#include "Triangle.h"


float points[] = {
   0.0f, 0.5f, 0.0f,
   0.5f, -0.5f, 0.0f,
  -0.5f, -0.5f, 0.0f
};

typedef const float pole[2][4];

const pole b[] = {
	{ { -0.8f, -0.5f, 0.5f, 1 }, { 0, 0, 1, 1 } },
   { { -0.2f, -0.5f, 0.5f, 1 }, { 1, 0, 0, 1 } },
   { { -0.2f, 0.4f, 0.5f, 1 }, { 1, 1, 0, 1 } },
};

const pole a[] = {
	  { { 0.2f, -0.5f, 0.5f, 1 }, { 1, 0, 0, 1 } },
   { { 0.2f, 0.4f, 0.5f, 1 }, { 1, 1, 0, 1 } },
   { { 0.8f, -0.5f, 0.5f, 1 }, { 0, 1, 1, 1 } },
};




Triangle::Triangle(Shader* sh)
{
	this->setShader(sh);
	//vertex buffer object (VBO)
	GLuint VBO = 0;
	glGenBuffers(1, &VBO); // generate the VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(b), b, GL_STATIC_DRAW);
	this->VBO = VBO;

	//Vertex Array Object (VAO)
	GLuint VAO = 0;
	glGenVertexArrays(1, &VAO); //generate the VAO
	glBindVertexArray(VAO); //bind the VAO
	glEnableVertexAttribArray(0); //enable vertex attributes
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(b[0]), (GLvoid*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(b[0]), (GLvoid*)(4 * sizeof(GLfloat)));
	//glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VERTICES[0]), (GLvoid*)(4 * sizeof(GLfloat)));
	this->VAO = VAO;
}

