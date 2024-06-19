#pragma once 
#include "Core.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>



namespace LE
{
    namespace Shader 
    {
        MTL::RenderPipelineState* CreateRenderPipelineState(const char* shaderFilePath);
        MTL::ComputePipelineState* CreateComputePipelineState(const char* shaderFilePath);
    }
}