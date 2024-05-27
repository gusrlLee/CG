#include "Renderer.h"

#include "RenderRHI/Metal/Metal_Renderer.h"

namespace LE 
{
    Renderer::Renderer()
    {
        m_pRHI = new Metal_Renderer();
    }

    Renderer::~Renderer()
    {
        delete m_pRHI;
    }

    void Renderer::Init()
    {
        m_pRHI->Init();
    }
}