#pragma once 
#include "Core.h"

namespace LE 
{
    namespace Renderer
    {
        extern NS::AutoreleasePool* pool;
        
        void Init();

        void BeginFrame();
        void RenderQuad();
        void EndFrame();
    }
}