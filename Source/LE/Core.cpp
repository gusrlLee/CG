#include "Core.h"

namespace LE
{
    MTL::Device* g_Device = nullptr;

    void Init()
    {
        // Create device of current 
        g_Device = MTL::CreateSystemDefaultDevice();

        // GLFw init and Display setting 
        Display::Init();
        Renderer::Init();
    }

    void Shutdown()
    {
        Renderer::Shutdown();
        Display::Shutdown();
        g_Device->release();
    }
}