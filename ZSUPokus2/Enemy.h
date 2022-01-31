#pragma once
#include "AbsObject.h"
class Enemy :public AbsObject
{
public:
	Enemy() {
		dead = false;
	};
	Enemy(AbsObject const& p):
		AbsObject(p)
	{
		dead = false;
	}
	bool dead;
	int DoSomething()
	{
		if (!dead)
		{
			Action act = Action("rotatex", 90.0f);
			this->action = act;
			dead = true;
		}
		return 0;
	}
};

