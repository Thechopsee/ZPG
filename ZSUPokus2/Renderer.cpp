#include "Renderer.h"
#include <stdio.h>
#include <glm/ext/matrix_float4x4.hpp>
#include "Camera.h"
#include <glm/ext/matrix_clip_space.hpp>
#include "Shader.h"
#include "TextureManager.h"
#include <string>


void Renderer::drawObject(AbsObject* object, Camera* camera, std::vector<Light*> light, TextureManager* tm,int id)
{
    
    for (int i = 0; i < light.size(); i++)
    {
        std::string start = "lightu[";
        start.append(std::to_string(i));
        start.append("].");
        std::string temp = start;

        light[i]->Use(object->getShader(),start,camera);

        object->getShader()->setVec3(light[i]->world_position, "lightPos");
        temp = start;
        temp.append("lightColor");


        glm::vec3 lc = light[i]->light_color;

        object->getShader()->setVec3(lc, "lightColor");
    }
    object->getShader()->setFloat((float)light.size(), "numberOfLights");

    if (object->texture > 0)
    {
        object->getTextura()->useTexture(object->getShader()->shaderProgram);
        object->getTextura()->specialThingforRender(0);

    }
    if (object->hasNormalMap)
    {
        object->getNormalMap()->useMeLikeNormalMap(object->getShader()->shaderProgram);
    }
    
    
    object->getShader()->setMa4(camera->GetViewMatrix(), "viewMatrix");
    object->getShader()->setMa4(camera->projectionMatrix, "projectionMatrix");
    object->getShader()->setVec3(camera->getPosition(), "viewPos");
    object->getShader()->setVec3(object->getColor(), "objectColor");

    object->bindVertexArray();

    if (object->drawByElemts == true)
    {
        glStencilFunc(GL_ALWAYS, id, 0xFF);
        glDrawElements(GL_TRIANGLES, object->GetDrawBy(), GL_UNSIGNED_INT, NULL);
        
    }
    else
    {
        glStencilFunc(GL_ALWAYS, id, 0xFF);
        glDrawArrays(GL_TRIANGLES, 0, object->GetDrawBy());
    }
    if (object->texture > 0)
    {
        object->getTextura()->specialThingforRender(1);
    }
 
}
