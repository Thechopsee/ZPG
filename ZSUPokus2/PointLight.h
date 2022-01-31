#pragma once
#include "Light.h"
#include <string>
#include "Camera.h"
#include "Shader.h"
class PointLight :public Light
{
	public:
	PointLight(glm::vec3 light_color,glm::vec3 world_position, float constant, float linear, float quadratic)
	{
		this->point = true;
		this->light_color = light_color;
		this->world_position = world_position;
		this->constant = constant;
		this->linear = linear;
		this->quadratic = quadratic;
		this->light_direction = glm::vec3(0.0f, 0.0f, 0.0f);
	}
	void Use(Shader* sh, std::string start, Camera* cam)
	{
		std::string temp = start;
		temp = start;
		temp.append("position");
		sh->setVec3(this->world_position, temp.c_str());
		temp = start;
		temp.append("direction");
		sh->setVec3(this->light_direction, temp.c_str());
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

