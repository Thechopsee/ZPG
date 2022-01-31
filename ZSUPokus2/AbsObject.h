#pragma once
#include "Shader.h"
#include <GL/glew.h>
//Include GLFW  
#include <GLFW/glfw3.h>  
#include <glm/ext/vector_float3.hpp>
#include "Textura.h"
struct Action
{
	const char* action;
	float data;
	float data2;
	Action(const char* ac,float data)
	{
		this->action = ac;
		this->data = data;
	}
	Action(const char* ac, float data,float data2)
	{
		this->action = ac;
		this->data = data;
		this->data2 = data2;
	}
	Action()
	{
		return;
	}
};
class AbsObject
{
private:
	glm::vec3 position=glm::vec3(0.0f,0.0f,0.0f);
	glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);
	Shader* shader;
	
	long drawby=0;

	Textura* textura;
	Textura* NormalMap;
protected:
	Action action;

public:
	
	int id = 0;
	GLuint VAO=0;
	GLuint VBO=0;
	GLuint IBO=0;
	bool drawByElemts = false;
	bool hasNormalMap = false;
	int texture = -1;
	virtual int DoSomething() { return 1; };
	virtual void setAction(Action action) { this->action = action;};
	virtual Action GetAction() { return this->action; };
	virtual int GetDrawBy() { return (int)this->drawby; };
	virtual void SetDrawBy(int drawby) { this->drawby = drawby; };
	virtual void bindVertexArray() {glBindVertexArray(this->VAO);}
	void setShader(Shader* shader) { this->shader = shader; }
	Shader* getShader() { return this->shader; };
	virtual void useShader() { this->shader->useShader(); }
	virtual glm::vec3 GetPosition() { return this->position; };
	void setPosition(glm::vec3 position) { this->position = position; };
	virtual void setColor(glm::vec3 color)
	 {
		 this->color = color;
	 }
	 virtual glm::vec3 getColor()
	 {
		 return this->color;
	 }
	 void setTexture(Textura* txt)
	 {
		 this->textura = txt;
		 this->texture = 1;
	 }
	 void setNormalMap(Textura* nmap)
	 {
		 this->NormalMap = nmap;
		 this->hasNormalMap = true;
	 }
	 Textura* getTextura()
	 {
		 return this->textura;
	 }
	 Textura* getNormalMap()
	 {
		 return this->NormalMap;
	 }
	AbsObject();
	AbsObject(Shader *sh,const float verticles[],long drawby, int sizeofslice);

};

