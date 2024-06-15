#include "SwapChain.h"
#include "Graphics/Metal/MtSwapChain.h"

namespace Lee
{
    SwapChain* SwapChain::Create()
    {
        switch(SwapChain::GetAPI())
        {
            case RendererAPI::API::OpenGL:    return nullptr;
            case RendererAPI::API::Metal:   return new MtSwapChain();
            case RendererAPI::API::Vulkan:  return nullptr;
        }

        std::runtime_error("Unknown RendererAPI!");
    }
}