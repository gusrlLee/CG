#pragma once 

#include "Renderer/RenderPipeline.h"
#include "Metal/Metal.hpp"
#include "Metal/Metal.h"

namespace LE 
{
    class MtRenderPipeline : public RenderPipeline
    {
        public:
            MtRenderPipeline(MTL::RenderPipelineState* pRenderPipelineState);
            ~MtRenderPipeline() override;

        private:
            MTL::RenderPipelineState* m_RenderPipeline;
    };
}