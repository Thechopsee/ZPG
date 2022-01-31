#include "AbsObject.h"

AbsObject::AbsObject()
{
}

AbsObject::AbsObject(Shader *sh,const float verticles[],long drawby,int sizeofslice)
{
	this->drawby = drawby;
	this->action = Action("",0.0f);
	this->setShader(sh);
	//vertex buffer object (VBO)
	GLuint VBO = 0;
	glGenBuffers(1, &VBO); // generate the VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*sizeofslice*drawby, verticles, GL_STATIC_DRAW);
	this->VBO = VBO;

	//Vertex Array Object (VAO)
	GLuint VAO = 0;
	glGenVertexArrays(1, &VAO); //generate the VAO
	glBindVertexArray(VAO); //bind the VAO
	glEnableVertexAttribArray(0); //enable vertex attributes
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeofslice * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// texture coord attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeofslice * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
	this->VAO = VAO;
}
