#pragma once
#include "Shader.h"
#include <GLFW/glfw3.h>

#include <string>
#include "Camera.h"
class Shader;
class Light
{
protected:
	Light() {};
public:
	float constant=1.0f;
	float linear=1.0f;
	float quadratic=0.032f;
	float cut_off =25;

	bool spot = false;
	bool point = false;
	glm::vec3 world_position;
	glm::vec3 light_direction;
	glm::vec3 light_color;
	
	Light(glm::vec3 light_color, glm::vec3 world_position, glm::vec3 direction);
	virtual void Use(Shader* sh, std::string start, Camera* cam);
};

