#pragma once
#include "Scene.h"
#include "Renderer.h"
#include "Translator.h"
#include "ObjectFactory.h"
#include "AbsObject.h"
#include <vector>
#include "LightFactory.h"

enum ScenesEnum
{
	TESTING,
	SHADER_TEST,
	FORREST,
	FORREST_NEW,
};
Scene::Scene()
{
	this->textureman = new TextureManager();
	ScenesEnum scene = FORREST_NEW;
		if (scene == TESTING)
		{
			Textura* txt = textureman->prepareNewTexture("test.png");
			Textura* cubetx = textureman->prepareNewTexture("posx.jpg", "posy.jpg", "posz.jpg", "negx.jpg", "negy.jpg", "negz.jpg");
			Textura* housetxt = textureman->prepareNewTexture("model.png");
			Textura* sphere = textureman->prepareNewTexture("albedo.png");
			Textura* spherenmp = textureman->prepareNewTexture("normalmap.png");
			this->camera = new Camera();
			this->light.push_back(LightFactory::createLight(POINT, glm::vec3(0.0f, 0.0f, 5.0f),glm::vec3(0.0f,0.5f,0.0f),glm::vec3(1.0f,1.0f,1.0f)));
			this->light.push_back(LightFactory::createLight(SPOTLIGHT, glm::vec3(0.0f, 0.0f, 5.0f), glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)));
			this->light.push_back(LightFactory::createLight(DIRECT, glm::vec3(0.0f, 0.0f, -30.0f), glm::vec3(0.0f, -10.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)));

			AbsObject* cubee = ObjectFactory::fabricateObjekt(SKYBOX, TEX_SKY, glm::vec3(0.0f, 0.0f, -15.0f));
			//cubee->setAction(Action("mbb", 0.0f));
			cubee->setColor(glm::vec3(1.0f, 0.0f, 0.0f));
			cubee->setTexture(cubetx);
			this->objekty.push_back(cubee);

			AbsObject* plain = ObjectFactory::fabricateObjekt(PLAIN2, TEXTURED, glm::vec3(0.0f, 0.0f, -10.0f));
			plain->setColor(glm::vec3(1.0f, 0.0f, 0.0f));
			plain->setTexture(textureman->findByName("test.png"));

			this->objekty.push_back(plain);

			AbsObject* obj = ObjectFactory::fabricateObjekt(TREE,PHONG, glm::vec3(-5.0f, 19.0f, 10.0f));
			obj->setColor(glm::vec3(0.0f, 0.7f, 0.0f));
			this->objekty.push_back(obj);

			AbsObject* obj2 = ObjectFactory::fabricateObjekt(HOUSE, NEW_PHONG, glm::vec3(-5.0f, 19.0f, 10.0f));
			obj2->setTexture(textureman->findByName("model.png"));
			obj2->setColor(glm::vec3(0.0f, 0.7f, 0.0f));
			this->objekty.push_back(obj2);

			AbsObject* obj3 = ObjectFactory::fabricateObjekt(SPHERE_NEW, NEW_PHONG, glm::vec3(-5.0f, 19.0f, 10.0f));
			obj3->setTexture(textureman->findByName("albedo.png"));
			obj3->setNormalMap(textureman->findByName("normalmap.png"));
			obj3->setColor(glm::vec3(0.0f, 0.7f, 0.0f));
			obj3->setAction(Action("mbb", 0.5f,0.1f));
			
			this->objekty.push_back(obj3);


			AbsObject* SA = ObjectFactory::fabricateObjekt(ASSIMP_OBJECT, PHONG, glm::vec3(-5.0f, 19.0f, 10.0f),"Stadium_arcadium.stl");
			SA->setColor(glm::vec3(0.0f, 0.7f, 0.0f));
			this->objekty.push_back(SA);
			
		}
		else if(scene== FORREST_NEW)
		{

			textureman->prepareNewTexture("test.png");
			textureman->prepareNewTexture("zombie.png");
			textureman->prepareNewTexture("model.png");
			textureman->prepareNewTexture("tree.png");
			textureman->prepareNewTexture("star_x.jpg", "star_y.jpg", "star_z.jpg", "star_nx.jpg", "star_ny.jpg", "star_nz.jpg");
			AbsObject* cubee = ObjectFactory::fabricateObjekt(SKYBOX, TEX_SKY, glm::vec3(0.0f, 0.0f, -15.0f));
			cubee->setColor(glm::vec3(1.0f, 0.0f, 0.0f));
			cubee->setTexture(textureman->findByName("star_x.jpg"));
			this->objekty.push_back(cubee);

			this->camera = new Camera();
			this->light.push_back(LightFactory::createLight(POINT, glm::vec3(10.0f, 19.0f, 5.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)));
			this->light.push_back(LightFactory::createLight(SPOTLIGHT, glm::vec3(0.0f, 0.0f, 5.0f), glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)));
			this->light.push_back(LightFactory::createLight(DIRECT, glm::vec3(0.0f, 0.0f, -30.0f), glm::vec3(-20.0f, -10.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)));

			AbsObject* plain = ObjectFactory::fabricateObjekt(TEREN, TEXTURED, glm::vec3(0.0f, 0.0f, -15.0f));

			//plain->setColor(glm::vec3(1.0f, 0.0f, 0.0f));
			plain->setTexture(textureman->findByName("test.png"));
			this->objekty.push_back(plain);

			AbsObject* cube2 = ObjectFactory::fabricateObjekt(HOUSE, TEXTURED, glm::vec3(2.0f, 19.0f, 22.0f));
			cube2->setTexture(textureman->findByName("model.png"));
			this->objekty.push_back(cube2);

			AbsObject* obj = ObjectFactory::fabricateObjekt(TREE, PHONG, glm::vec3(-5.0f, 19.0f, 10.0f));
			obj->setColor(glm::vec3(0.0f, 0.7f, 0.0f));
			this->objekty.push_back(obj);

			obj = ObjectFactory::fabricateObjekt(TREE, PHONG, glm::vec3(-15.0f, 19.0f, 30.0f));
			obj->setColor(glm::vec3(0.0f, 0.7f, 0.0f));
			this->objekty.push_back(obj);

			AbsObject* new_tree = ObjectFactory::fabricateObjekt(NEW_TREE, TEXTURED, glm::vec3(15.0f, 19.0f, 25.0f));
			new_tree->setTexture(textureman->findByName("tree.png"));
			this->objekty.push_back(new_tree);
			AbsObject* zombie = ObjectFactory::fabricateObjekt(ZOMBIE, FINAL_PHONG, glm::vec3(0.0f, 19.0f, 45.0f));
			zombie->setTexture(textureman->findByName("zombie.png"));
			this->objekty.push_back(zombie);

			AbsObject* LOGO = ObjectFactory::fabricateObjekt(STADIUMA, PHONG, glm::vec3(-0.0f, 0.5f, 30.0f));
			LOGO->setColor(glm::vec3(0.937, 0.792, 0.071));
			//LOGO->setAction(Action("rotatey", 90.0f));
			this->objekty.push_back(LOGO);

		}
		else if (scene == SHADER_TEST)
		{
			this->camera = new Camera();
			//this->light.push_back(ObjectFactory::createLight(POINT, glm::vec3(0.0f, 0.0f, 5.0f)));
			
			Textura* sphereTXT= textureman->prepareNewTexture("albedo.png");
			Textura* spherenmp = textureman->prepareNewTexture("normalmap.png");
			this->light.push_back(LightFactory::createLight(DIRECT, glm::vec3(0.0f, 0.0f, -30.0f), glm::vec3(0.0f, -10.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)));
			this->light.push_back(LightFactory::createLight(SPOTLIGHT, glm::vec3(0.0f, 0.0f, -30.0f), glm::vec3(0.0f, -10.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)));
			this->light.push_back(LightFactory::createLight(POINT, glm::vec3(0.0f, 3.0f, 0.0f), glm::vec3(0.0f, -10.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)));
			AbsObject* sphere = ObjectFactory::fabricateObjekt(SPHERE_NEW, PHONG, glm::vec3(-5.0f, 0.0f, 0.0));
			//sphere->setTexture(textureman->findByName("albedo.png"));
			//sphere->setNormalMap(textureman->findByName("normalmap.png"));
			AbsObject* sphere1 = ObjectFactory::fabricateObjekt(SPHERE_NEW, PHONG, glm::vec3(5.0f, 0.0f, 0.0));
			//sphere1->setTexture(textureman->findByName("albedo.png"));
			//sphere1->setNormalMap(textureman->findByName("normalmap.png"));
			AbsObject* sphere2 = ObjectFactory::fabricateObjekt(SPHERE_NEW,PHONG, glm::vec3(0.0f, 5.2f, 0.0));
			//sphere2->setTexture(textureman->findByName("albedo.png"));
			//sphere2->setNormalMap(textureman->findByName("normalmap.png"));
			AbsObject* sphere3 = ObjectFactory::fabricateObjekt(SPHERE_NEW, PHONG, glm::vec3(0.0f, -5.2f, 0.0));
			//sphere3->setTexture(textureman->findByName("albedo.png"));
			//sphere3->setNormalMap(textureman->findByName("normalmap.png"));
			sphere->setColor(glm::vec3(1.0f, 0.0f, 0.0f));
			this->objekty.push_back(sphere);
			this->objekty.push_back(sphere1);
			this->objekty.push_back(sphere2);
			this->objekty.push_back(sphere3);
		}
		else if (scene = FORREST)
		{
			this->camera = new Camera();
			srand(time(NULL));
			this->light.push_back(LightFactory::createLight(DIRECT, glm::vec3(0.0f, 0.0f, -30.0f), glm::vec3(0.0f, -10.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)));
			for (int i = 0; i < 10; i++)
			{
				int rand_factor =rand() % 6;
				rand_factor -= 3;
				AbsObject* obj = ObjectFactory::fabricateObjekt(TREE, PHONG, glm::vec3(-5.0f+rand_factor, 0.0f, i*(-5.0f)));
				obj->setColor(glm::vec3(0.0f, 0.7f, 0.0f)); 

					rand_factor *= -1;

				AbsObject* bush = ObjectFactory::fabricateObjekt(BUSHES, PHONG, glm::vec3(-5.0f + rand_factor, 0.0f, i * (-5.0f)));
				bush->setColor(glm::vec3(0.1f, 0.3f, 0.1f));
				rand_factor = rand() % 6;
				rand_factor -= 3;
				AbsObject* obj2 = ObjectFactory::fabricateObjekt(TREE, PHONG, glm::vec3(-10.0f + rand_factor, 0.0f, i * (-5.0f)));
				obj2->setColor(glm::vec3(0.0f, 0.7f, 0.0f));

					rand_factor *= -1;
			
				AbsObject* bush2 = ObjectFactory::fabricateObjekt(BUSHES, PHONG, glm::vec3(-5.0f + rand_factor, 0.0f, i * (-5.0f)));
				bush2->setColor(glm::vec3(0.1f, 0.3f, 0.1f));
				rand_factor = rand() % 6;
				rand_factor -= 3;
				AbsObject* obj3 = ObjectFactory::fabricateObjekt(TREE, PHONG, glm::vec3(-15.0f + rand_factor, 0.0f, i * (-5.0f)));
				obj3->setColor(glm::vec3(0.0f, 0.7f, 0.0f));

					rand_factor *= -1;
			
				AbsObject* bush3 = ObjectFactory::fabricateObjekt(BUSHES, PHONG, glm::vec3(-5.0f + rand_factor, 0.0f, i * (-5.0f)));
				bush3->setColor(glm::vec3(0.1f, 0.3f, 0.1f));
				this->objekty.push_back(obj);
				this->objekty.push_back(obj2);
				this->objekty.push_back(obj3);
				this->objekty.push_back(bush);
				this->objekty.push_back(bush2);
				this->objekty.push_back(bush3);
			}
			for (int i = 0; i < 10; i++)
			{
				int rand_factor = rand() % 6;
				rand_factor -= 3;
				AbsObject* obj = ObjectFactory::fabricateObjekt(TREE, PHONG, glm::vec3(5.0f + rand_factor, 0.0f, i * (-5.0f)));
				obj->setColor(glm::vec3(0.0f, 0.7f, 0.0f));

					rand_factor *= -1;


				AbsObject* bush = ObjectFactory::fabricateObjekt(BUSHES, PHONG, glm::vec3(5.0f + rand_factor, 0.0f, i *(-5.0f)));
				bush->setColor(glm::vec3(0.1f, 0.3f, 0.1f));
				rand_factor = rand() % 6;
				rand_factor -= 3;
				AbsObject* obj2 = ObjectFactory::fabricateObjekt(TREE, PHONG, glm::vec3(10.0f + rand_factor, 0.0f, i * (-5.0f)));
				obj2->setColor(glm::vec3(0.0f, 0.7f, 0.0f));

					rand_factor *= -1;


				AbsObject* bush2 = ObjectFactory::fabricateObjekt(BUSHES, PHONG, glm::vec3(10.0f + rand_factor, 0.0f, i *  (-5.0f)));
				bush2->setColor(glm::vec3(0.1f, 0.3f, 0.1f));
				rand_factor = rand() % 6;
				rand_factor -= 3;
				AbsObject* obj3 = ObjectFactory::fabricateObjekt(TREE, PHONG, glm::vec3(15.0f + rand_factor, 0.0f, i * (-5.0f)));
				obj3->setColor(glm::vec3(0.0f, 0.7f, 0.0f));

					rand_factor *= -1;

				AbsObject* bush3 = ObjectFactory::fabricateObjekt(BUSHES, PHONG, glm::vec3(15.0f + rand_factor, 0.0f, i *  (-5.0f)));
				bush3->setColor(glm::vec3(0.1f, 0.3f, 0.1f));
				this->objekty.push_back(obj);
				this->objekty.push_back(obj2);
				this->objekty.push_back(obj3);
				this->objekty.push_back(bush);
				this->objekty.push_back(bush2);
				this->objekty.push_back(bush3);
			}
			for (int i = 0; i < 4; i++)
			{
				int rand_factor = rand() % 6;
				rand_factor -= 3;
				AbsObject* obj = ObjectFactory::fabricateObjekt(GIFT, PHONG, glm::vec3((float)rand_factor, 0.0f, i*3 * (-5.0f)));
				obj->setColor(glm::vec3(0.8f, 0.1f, 0.3f));
				this->objekty.push_back(obj);
			}
			AbsObject* plain = ObjectFactory::fabricateObjekt(PLAIN, LAMBERT, glm::vec3(0.0f, 0.0f, -25.0f));
			plain->setColor(glm::vec3(0.39f, 0.26f, 0.13f));
			plain->setAction(Action("scale", 28.0f));
			this->objekty.push_back(plain);

		}
		else
		{
			this->camera = new Camera();
			this->light.push_back(LightFactory::createLight(DIRECT, glm::vec3(0.0f, 0.0f, -30.0f), glm::vec3(0.0f, -10.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)));
			AbsObject* tr = ObjectFactory::fabricateObjekt(TRIANGLE, KONSTANTNI, glm::vec3(-1.5f, -2.2f, -10.0f));
			this->objekty.push_back(tr);
			AbsObject* tr2 = ObjectFactory::fabricateObjekt(TRIANGLE, KONSTANTNI, glm::vec3(-7.5f, -5.2f, -10.0f));
			AbsObject* cube = ObjectFactory::fabricateObjekt(CUBE, PHONG, glm::vec3(-5.5f, 9.2f, -10.0f));
			AbsObject* sphere = ObjectFactory::fabricateObjekt(SPHERE, LAMBERT, glm::vec3(-15.5f, -2.2f, -10.0));
			AbsObject* suzi = ObjectFactory::fabricateObjekt(SUZI, KONSTANTNI, glm::vec3(10.5f, +0.2f, -10.0f));



			this->objekty.push_back(cube);
			this->objekty.push_back(tr2);
			this->objekty.push_back(sphere);
			this->objekty.push_back(suzi);
		}


		
	
}

void Scene::renderAll()
{
	glEnable(GL_STENCIL_TEST);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

	int pos=0;
	for (AbsObject* i : objekty)
	{
		
		if (i->texture > 0)
		{
			if (i->getTextura()->imCube())
			{
				i->setPosition(camera->getPosition());
			}
		}
		i->useShader();
		if (strcmp(i->GetAction().action, "rotatex") == 0)
		{
			Translator::rotate(i, glm::vec3(1.0f, 0.0f, 0.0f), i->GetAction().data);
		}
		else if (strcmp(i->GetAction().action, "rotatey") == 0)
		{
			Translator::rotate(i, glm::vec3(0.0f, 1.0f, 0.0f), i->GetAction().data);
		}
		else if (strcmp(i->GetAction().action, "scale") == 0)
		{
			Translator::scale(i,i->GetAction().data);
		}
		else if (strcmp(i->GetAction().action, "rotatefullx") == 0)
		{
			Translator::rotate(i, glm::vec3(1.0f, 0.0f, 0.0f), (float)glfwGetTime());
		}
		else if (strcmp(i->GetAction().action, "rotatefully") == 0)
		{
			Translator::rotate(i, glm::vec3(0.0f, 1.0f, 0.0f), (float)glfwGetTime());
		}
		else if (strcmp(i->GetAction().action, "mbb")==0)
		{
			Action a = i->GetAction();
			glm::mat4 A = glm::mat4(glm::vec4(-1.0, 3.0, -3.0, 1.0),
				glm::vec4(3.0, -6.0, 3.0, 0),
				glm::vec4(-3.0, 3.0, 0, 0),
				glm::vec4(1, 0, 0, 0));
			glm::mat4x3 B = glm::mat4x3(glm::vec3(-1, 0, 0),
				glm::vec3(0, 1, 0),
				glm::vec3(0, -1, 0),
				glm::vec3(1, 0, 0));
			Translator::movebyBezier(i, a.data, A, B);
			if (a.data >= 1.0f || a.data <= 0.0f)  a.data2 *= -1;
			a.data = a.data + a.data2;
			i->setAction(a);
		}
		else
		{
			Translator::None(i);
		}
		pos++;

		Renderer::drawObject(i, this->camera, this->light, this->textureman, pos);
		
	}
}

void Scene::createNewObject(AbsObject* object)
{
	objekty.push_back(object);
}

Camera* Scene::getCamera()
{
	return this->camera;
}
