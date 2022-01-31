#pragma once
#include "Textura.h"
#include <iostream>
class Cubemap : public Textura
{
public:
	Cubemap(const char* pathx, const char* pathy, const char* pathz, const char* pathnx, const char* pathny, const char* pathnz, int tu);

	void specialThingforRender(bool prom);
	
	bool imCube();

};

