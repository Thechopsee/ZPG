#include "Light.h"

Light::Light(glm::vec3 light_color, glm::vec3 world_position, glm::vec3 direction)
{
	this->light_color = light_color;
	this->world_position = world_position;
	this->light_direction = direction;
}

void Light::Use(Shader* sh, std::string start, Camera* cam)
{
	std::string temp = start;
	temp = start;
	temp.append("imdirect");
	sh->setBool(true, temp.c_str());
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
