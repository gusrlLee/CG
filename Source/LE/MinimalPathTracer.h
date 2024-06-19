#pragma once 
#include "Core.h"
#include <iostream>

namespace LE
{
    class MinimalPathTracer 
    {
        public:
            MinimalPathTracer();
            ~MinimalPathTracer();

            void Render();

        private:
            MTL::ComputePipelineState* m_PathTracingRenderPass;

    }
}