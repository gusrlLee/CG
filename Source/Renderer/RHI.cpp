#include "RHI.h"
#include "Graphics/Metal/MtRHI.h"

namespace Lee 
{
#ifdef USE_OPENGL_API
    RHI::API RHI::s_API = RHI::API::OpenGL;
#endif

#ifdef USE_METAL_API
    RHI::API RHI::s_API = RHI::API::Metal;
#endif

#ifdef USE_VULKAN_API
    RHI::API RHI::s_API = RHI::API::Vulkan;
#endif

#ifdef USE_D3D12_API
    RHI::API RHI::s_API = RHI::API::D3D12
#endif

    RHI* RHI::Create()
    {
        switch(RHI::GetAPI())
        {
            case RHI::API::OpenGL:  return nullptr;
            case RHI::API::Metal:   return new MtRHI();
            case RHI::API::Vulkan:  return nullptr;
            case RHI::API::D3D12:   return nullptr;
        }

        return nullptr;
    }

}