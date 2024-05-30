#include "MtDevice.h"

namespace LE 
{
    MtDevice::MtDevice()
    {
        m_Device = MTL::CreateSystemDefaultDevice();
    }

    MtDevice::~MtDevice()
    {
        m_Device->release();
    }

    CommandQueue* MtDevice::CreateCommandQueue()
    {
        CommandQueue* pCommandQueue = new MtCommandQueue(m_Device->newCommandQueue());
        return pCommandQueue;
    }

    RenderPipeline* MtDevice::CreateRenderPipeline(std::string shaderSource, std::string vertexFunctionName, std::string fragmentFunctionName) 
    {
        NS::Error* pError = nullptr;
        MTL::Library* pLibrary = m_Device->newLibrary(NS::String::string(shaderSource.c_str(), NS::ASCIIStringEncoding), nullptr, &pError);
        if ( !pLibrary )
        {
            std::runtime_error("Failed to create Library!");
        }

        MTL::Function* pVertexFunc = pLibrary->newFunction(NS::String::string(vertexFunctionName.c_str(), NS::ASCIIStringEncoding));
        MTL::Function* pFragmentFunc = pLibrary->newFunction(NS::String::string(fragmentFunctionName.c_str(), NS::ASCIIStringEncoding));

        MTL::RenderPipelineDescriptor* pDesc = MTL::RenderPipelineDescriptor::alloc()->init();
        pDesc->setVertexFunction( pVertexFunc );
        pDesc->setFragmentFunction( pFragmentFunc );
        pDesc->colorAttachments()->object(0)->setPixelFormat( MTL::PixelFormat::PixelFormatBGRA8Unorm_sRGB );

        MTL::RenderPipelineState* pPSO = m_Device->newRenderPipelineState(pDesc, &pError);
        if ( !pPSO )
        {
            std::runtime_error("Failed to create RenderPipeline");
        }
        pDesc->release();

        RenderPipeline* pRenderPipeline = new MtRenderPipeline(pPSO);

        return pRenderPipeline;
    }
}