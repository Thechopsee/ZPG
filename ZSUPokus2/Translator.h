#pragma once
#include <GL/glew.h>
#include "AbsObject.h"

class Translator
{
public:
	static void movebyBezier(AbsObject* obj,float t,glm::mat4 A,glm::mat4 B);
	static void rotate(AbsObject* obj, glm::vec3 direction, float angle);
	static void scale(AbsObject* obj, float nasobek);
	static void None(AbsObject* obj);
};

