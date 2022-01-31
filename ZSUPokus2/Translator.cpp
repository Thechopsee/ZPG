
#include "Translator.h"


void Translator::movebyBezier(AbsObject* obj, float t, glm::mat4 A, glm::mat4 B)
{
	glm::mat4 M = glm::mat4(1.0f);
	M = glm::translate(M, obj->GetPosition());
	glm::vec4 parameters = glm::vec4(t * t * t, t * t, t, 1.0f);
	glm::vec3 p = parameters * A * glm::transpose(B);
	M = glm::translate(M,p);
	obj->getShader()->setMa4(M, "modelMatrix");

}

void Translator::rotate(AbsObject* obj,glm::vec3 direction,float angle)
{
    glm::mat4 M = glm::mat4(1.0f);
	M = glm::translate(M, obj->GetPosition());
	M = glm::rotate(M, angle, direction);
	//po�li
	obj->getShader()->setMa4(M, "modelMatrix");
}

void Translator::scale(AbsObject* obj,float nasobek)
{
	glm::mat4 M = glm::mat4(1.0f);
	//najdi

	M = glm::translate(M, obj->GetPosition());
	M = glm::scale(M, glm::vec3(nasobek));
	obj->getShader()->setMa4(M, "modelMatrix");
}

void Translator::None(AbsObject* obj)
{
	glm::mat4 M = glm::mat4(1.0f);
	//najdi

	M = glm::translate(M, obj->GetPosition());
	obj->getShader()->setMa4(M, "modelMatrix");
}
