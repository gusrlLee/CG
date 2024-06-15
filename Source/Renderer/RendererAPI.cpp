#include "RendererAPI.h"

namespace Lee 
{
#ifdef USE_OPENGL_API
    RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;
#endif

#ifdef USE_METAL_API
    RendererAPI::API RendererAPI::s_API = RendererAPI::API::Metal;
#endif

#ifdef USE_VULKAN_API
    RendererAPI::API RendererAPI::s_API = RendererAPI::API::Vulkan;
#endif

#ifdef USE_D3D12_API

#endif
}