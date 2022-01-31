#include "LightFactory.h"

Light* LightFactory::createLight(LightEnum type, glm::vec3 position_light,glm::vec3 direction, glm::vec3 color)
{
	switch (type)
	{
	case SPOTLIGHT:
		return new Spotlight(color,direction,position_light, 0.976f, 1.0f, 0.09f, 0.032f);
	case POINT:
		return new PointLight(color, position_light, 1.0f, 0.09f, 0.032f);
	case DIRECT:
		return new Light(color,position_light,direction);
	}


}
