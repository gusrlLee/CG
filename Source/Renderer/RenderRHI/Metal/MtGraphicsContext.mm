#include "MtGraphicsContext.h"
#include "Renderer/GraphicsContext.h"
#include "Renderer/RenderRHI/GraphicsContextBridge.h"

namespace LE 
{
    GraphicsContext* CreateMetalGraphicsContext()
    {
        return new MtGraphicsContext();
    }

    Device* MtGraphicsContext::CreateDevice()
    {
        return new MtDevice();
    }
    
}