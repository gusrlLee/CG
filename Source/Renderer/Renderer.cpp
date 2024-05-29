#include "Renderer.h"

#include "RenderRHI/GraphicsContextBridge.h"

namespace LE 
{
    Renderer::Renderer()
    {
        // m_pRHI = CreateRenderRHI_Metal();
        // if we use Metal API 
        m_GraphicsContext = CreateMetalGraphicsContext();
    }

    Renderer::~Renderer()
    {
        // delete m_pRHI;
        delete m_Device;
    }

    void Renderer::Init()
    {
        // m_pRHI->Init();
    }
    
    void Renderer::Init(GLFWwindow* pWindow)
    {
        // m_pRHI->Init(pWindow);
        m_Device = m_GraphicsContext->CreateDevice();
    }
}