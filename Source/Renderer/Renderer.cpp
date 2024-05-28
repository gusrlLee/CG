#include "Renderer.h"

#include "RenderRHI/GraphicsContextBridge.h"

namespace LE 
{
    Renderer::Renderer()
    {
        m_pRHI = CreateRenderRHI_Metal();
    }

    Renderer::~Renderer()
    {
        delete m_pRHI;
    }

    void Renderer::Init()
    {
        m_pRHI->Init();
    }
    
    void Renderer::Init(GLFWwindow* pWindow)
    {
        m_pRHI->Init(pWindow);
    }
}