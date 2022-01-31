#pragma once
#include "Cube.h"
#pragma once
#include "AbsObject.h"
#include "Triangle.h"
#include "Shader.h"
#include "Light.h"
#include "tree.h"
#include "sphere.h"
#include "suzi_smooth.h"
#include "gift.h"
#include "plain.h"
#include "bushes.h"
#include "ShaderFactory.h"
#include "plain2.h"
#include "sky.h"

#pragma once


#include "Textura.h"

enum ObjectEnum
{
	TRIANGLE=1,
	CUBE=2,
	SPHERE=3,
	SUZI=4,
	TREE,
	GIFT,
	PLAIN,
	BUSHES,
	PLAIN2,
	SKYBOX,
	HOUSE,
    POKEMON,
    STADIUMA,
    TEREN,
    NEW_TREE,
    ZOMBIE,
    SPHERE_NEW,
    ASSIMP_OBJECT
};


class ObjectFactory
{
public:
    
     static AbsObject* fabricateObjekt(ObjectEnum object_type, ShaderEnum shader_type, glm::vec3 position, const char* path = "none");

     static AbsObject* createObject(ObjectEnum object_type, ShaderEnum shader_type, const char* path = "none");
};

