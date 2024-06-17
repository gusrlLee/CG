#include "MtRHI.h"
#include "GLFWAdapter.h"

namespace Lee
{
    void MtRHI::Init(GLFWwindow* pWindow)
    {
        printf("Init()!\n");
        m_Device = MTL::CreateSystemDefaultDevice();

        m_MetalLayer = CA::MetalLayer::layer()->retain();
        m_MetalLayer->setDevice(m_Device);
        m_MetalLayer->setPixelFormat(MTL::PixelFormat::PixelFormatBGRA8Unorm);

        m_WindowDelegate = GetNSWindow(pWindow, m_MetalLayer)->retain();
    }

    void MtRHI::Release()
    {
        m_WindowDelegate->release();
        m_MetalLayer->release();
        m_Device->release();
        printf("Release()!\n");
    }

    void MtRHI::Draw()
    {
        NS::AutoreleasePool* pool = NS::AutoreleasePool::alloc()->init();
        this->Drawable();
        pool->release();
    }

    void MtRHI::Drawable()
    {
        m_SwapChain = m_MetalLayer->nextDrawable();
    }
}