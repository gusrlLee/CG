#pragma once 
#include "Renderer/RenderRHI.h"
#include "Renderer/GraphicsContext.h"

namespace LE 
{
    // RenderRHI* CreateRenderRHI_Metal();
    GraphicsContext* CreateMetalGraphicsContext();
    // RenderRHI* CreateRenderRHI_D3D12();
    // RenderRHI* CreateRenderRHI_Vulkan();
}