#include "MtRenderPipeline.h"

namespace LE
{
    MtRenderPipeline::MtRenderPipeline(MTL::RenderPipelineState* pRenderPipelineState)
    {
        m_RenderPipeline = pRenderPipelineState;
    }

    MtRenderPipeline::~MtRenderPipeline()
    {
        m_RenderPipeline->release();
    }
}