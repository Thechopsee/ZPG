#pragma once
#include "Light.h"
#include "Spotlight.h"
#include "PointLight.h"

enum LightEnum
{
	SPOTLIGHT,
	POINT,
	DIRECT
};

class LightFactory
{
public:
	static Light* createLight(LightEnum type, glm::vec3 position_light, glm::vec3 direction, glm::vec3 color);
};

