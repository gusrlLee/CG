#include "Core.h"

namespace LE
{
    MTL::Device* g_Device = nullptr;

    void Init()
    {
        // Create device of current 
        g_Device = MTL::CreateSystemDefaultDevice();

        Display::Init();
    }

    void Shutdown()
    {
        Display::Shutdown();
        g_Device->release();
    }
}