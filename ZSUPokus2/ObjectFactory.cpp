#include "ObjectFactory.h"
#include "AsimpLoader.h"
#include "Enemy.h"

AbsObject* ObjectFactory::fabricateObjekt(ObjectEnum object_type, ShaderEnum shader_type, glm::vec3 position, const char* path)
{
    AbsObject* obj = new AbsObject();
    if (object_type == ASSIMP_OBJECT && strcmp(path, "none") == 0)
    {
        printf("bad calling of object");
    }
    else if (object_type == ASSIMP_OBJECT)
    {
        obj = ObjectFactory::createObject(object_type, shader_type, path);
    }
    else
    {
        obj = ObjectFactory::createObject(object_type, shader_type);
    }

    obj->setPosition(position);
    return obj;

}

AbsObject* ObjectFactory::createObject(ObjectEnum object_type, ShaderEnum shader_type, const char* path)
{
    AbsObject* object;
    Enemy* en;
    switch (object_type)
    {
    case TRIANGLE:
        return new Triangle(ShaderFactory::makeShader(shader_type));
    case CUBE:
        return new AbsObject(ShaderFactory::makeShader(shader_type), Cubev, 36, 8);
    case SPHERE:
        return new AbsObject(ShaderFactory::makeShader(shader_type), sphere, 2880, 6);
    case SUZI:
        return new AbsObject(ShaderFactory::makeShader(shader_type), suziSmooth, 2904, 6);
    case TREE:
        return new AbsObject(ShaderFactory::makeShader(shader_type), tree, 92814, 6);
    case GIFT:
        return new AbsObject(ShaderFactory::makeShader(shader_type), gift, 66624, 6);
    case PLAIN:
        return new AbsObject(ShaderFactory::makeShader(shader_type), plain, 6, 6);
    case BUSHES:
        return new AbsObject(ShaderFactory::makeShader(shader_type), bushes, 8730, 6);
    case PLAIN2:
        return new AbsObject(ShaderFactory::makeShader(shader_type), plain2, 6, 8);
    case SKYBOX:
        return new AbsObject(ShaderFactory::makeShader(shader_type), skyboxVertices, 36, 3);
    case HOUSE:
        object = AsimpLoader::load("model.obj");
        object->setAction(Action("", 0.0f));
        object->setShader(ShaderFactory::makeShader(shader_type));
        return object;
    case POKEMON:
        object = AsimpLoader::load("pikachu.stl");
        object->setAction(Action("scale", 0.1f));
        object->setShader(ShaderFactory::makeShader(shader_type));
        return object;
    case STADIUMA:
        object = AsimpLoader::load("Stadium_arcadium.stl");
        object->setAction(Action("scale", 0.1f));
        object->setShader(ShaderFactory::makeShader(shader_type));
        return object;
    case TEREN:
        object = AsimpLoader::load("teren.stl");
        object->setAction(Action("scale", 0.5f));
        object->setShader(ShaderFactory::makeShader(shader_type));
        return object;
    case NEW_TREE:
        object = AsimpLoader::load("tree.obj");
        object->setAction(Action("scale", 0.1f));
        object->setShader(ShaderFactory::makeShader(shader_type));
        return object;
    case ZOMBIE:
        en = (Enemy *)AsimpLoader::load("zombie.obj");
        en->setAction(Action("scale", 1.1f));
        en->setShader(ShaderFactory::makeShader(shader_type));
        return en;
    case SPHERE_NEW:
        object = AsimpLoader::load("sphere.obj");
        object->setAction(Action("scale", 1.1f));
        object->setShader(ShaderFactory::makeShader(shader_type));
        return object;
    case ASSIMP_OBJECT:
        object = AsimpLoader::load(path);
        object->setAction(Action("scale", 0.1f));
        object->setShader(ShaderFactory::makeShader(shader_type));
        return object;
    }


}
