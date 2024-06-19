#pragma once 
#include "Core.h"
#include "VertexData.h"
#include "Shader.h"
#include "Scene.h"
#include "Display.h"

namespace LE 
{
    namespace Renderer
    {
        extern NS::AutoreleasePool* pool;
        extern MTL::CommandQueue* pCommandQueue;
        extern MTL::CommandBuffer* pCommandBuffer;
        extern MTL::RenderPipelineState* pRenderPSO;
        extern MTL::Buffer* squareVertexBuffer;
        extern class Scene* grassTexture;
        
        void Init();
        void Shutdown();
        void BeginFrame();
        void RenderQuad();
        void EndFrame();
    }
}