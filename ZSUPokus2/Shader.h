#pragma once
#include <GL/glew.h>
//Include GLFW  
#include <GLFW/glfw3.h>  
#pragma once 
#include "Light.h"
#include "ShaderLoader.h"
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/ext/vector_float3.hpp>

class Shader :public ShaderLoader
{
public:
	Shader(const char* vertex,const char* fragment);
	void checkError();
	void useShader();
	void setMa4(glm::mat4 matrix, const char* adress);
	void setVec3(glm::vec3 vector, const char* adress);
	void setVec4(glm::vec4 vecto, const char* adress);
	void setBool(bool neco, const char* adress);
	void setFloat(float neco, const char* adress);
};

