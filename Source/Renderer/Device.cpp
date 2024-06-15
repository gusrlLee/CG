#include "Device.h"
#include "Graphics/Metal/MtDevice.h"

namespace Lee
{
    Device* Device::Create()
    {
        switch(Device::GetAPI())
        {
            case RendererAPI::API::OpenGL:    return nullptr;
            case RendererAPI::API::Metal:   return new MtDevice();
            case RendererAPI::API::Vulkan:  return nullptr;
        }

        std::runtime_error("Unknown RendererAPI!");
    }
}