#pragma once
#include <vector>
#pragma once
#include "AbsObject.h"
#include "Camera.h"
#include "Light.h"
#include "TextureManager.h"
#include "ObjectFactory.h"



class Scene
{
private:
	std::vector<AbsObject*> objekty;
	std::vector<Light*> light;

	TextureManager* textureman;
	Camera* camera;
public:
	Scene();
	void renderAll();
	void createNewObject(AbsObject* object);
	Camera* getCamera();
	void actionOnObject(int i,float x,float y,float z)
	{
		if (this->objekty[i]->DoSomething() == 1)
		{
			this->createNewObject(ObjectFactory::fabricateObjekt(SPHERE, PHONG, glm::vec3(x, y, z)));
		}
	}

};

