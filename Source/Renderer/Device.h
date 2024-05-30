#pragma once 
#include "CommandQueue.h"
// #include "ShaderLibrary.h"
#include "RenderPipeline.h"
#include "Buffer.h"
#include "Math/Vertex.h"

#include <iostream>
#include <string>

namespace LE 
{
    class Device 
    {
        public:
            virtual ~Device() = default;
            virtual CommandQueue* CreateCommandQueue() {}
            // virtual ShaderLibrary* CreateShaderLibrary(std::string shaderSource) {}
            virtual RenderPipeline* CreateRenderPipeline(std::string shaderSource, std::string vertexFunctionName, std::string fragmentFunctionName) {}
            virtual Buffer* CreateBuffer() {}
            virtual void Draw() {}
    };
}