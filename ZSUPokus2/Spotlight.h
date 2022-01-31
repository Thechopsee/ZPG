#pragma once
#include "Light.h"
#include "Camera.h"
#include "Shader.h"
#include <string>
class Spotlight :public Light
{
	public:
	Spotlight(glm::vec3 light_color, glm::vec3 direction, glm::vec3 world_position, float cut_off, float constant, float linear, float quadratic)
	{
		this->spot = true;
		this->light_color = light_color;
		this->world_position = world_position;
		this->cut_off = cut_off;
		this->constant = constant;
		this->linear = linear;
		this->quadratic = quadratic;
		this->light_direction = direction;
	}
	void Use(Shader* sh, std::string start, Camera* cam)
	{
		std::string temp = start;
		temp.append("imspot");
		sh->setBool(true, temp.c_str());
		temp = start;
		temp.append("position");
		sh->setVec3(cam->getPosition(), temp.c_str());
		temp = start;
		temp.append("direction");
		sh->setVec3(cam->getFront(), temp.c_str());
		temp = start;
		temp.append("cutOff");
		sh->setFloat(this->cut_off, temp.c_str());
		temp = start;
		temp.append("constant");
		sh->setFloat(this->constant, temp.c_str());
		temp = start;
		temp.append("linear");
		sh->setFloat(this->linear, temp.c_str());
		temp = start;
		temp.append("quadratic");
		sh->setFloat(this->quadratic, temp.c_str());
	}
};

