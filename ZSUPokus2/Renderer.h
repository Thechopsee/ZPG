#pragma once
#include "AbsObject.h"
#include "Camera.h"
#include "Light.h"
#include "TextureManager.h"

#include <vector>
class Renderer
{
public:
	static void drawObject(AbsObject* object, Camera* camera,std::vector<Light*> light, TextureManager* tm,int id);
};

