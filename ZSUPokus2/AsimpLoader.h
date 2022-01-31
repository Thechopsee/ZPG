#pragma once
#include <string>
#include "AbsObject.h"

#include<assimp/Importer.hpp>// C++ importerinterface
#include<assimp/scene.h>// aiSceneoutputdata structure
#include<assimp/postprocess.h>// Post processingflags

#include <glm/ext/vector_float4.hpp>

struct Vertex
{
    float Position[3];
    float Normal[3];
    float Texture[2];
    float Tangent[3];
};

class AsimpLoader
{
public:
    static AbsObject* load(std::string fileName);
    
};

