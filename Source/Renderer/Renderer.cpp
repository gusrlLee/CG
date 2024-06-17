#include "Renderer.h"

namespace Lee
{
    RHI* Renderer::s_RHI = RHI::Create();

    void Renderer::Init(Window* pWindow)
    {
        s_RHI->Init(pWindow->GetGLFWwindowPtr());
    }

    void Renderer::Release()
    {
        s_RHI->Release();
    }
    
    void Renderer::Draw()
    {
        s_RHI->Draw();
    }

    void Renderer::Drawable()
    {
        s_RHI->Drawable();
    }
}