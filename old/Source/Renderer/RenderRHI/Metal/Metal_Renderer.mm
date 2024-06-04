#include "Metal_Renderer.h"
#include "Renderer/RenderRHI/GraphicsContextBridge.h"
#include "Renderer/RenderRHI.h"
#include <iostream>

namespace LE 
{
    RenderRHI* CreateRenderRHI_Metal()
    {
        return new Metal_Renderer();
    }

    Metal_Renderer::Metal_Renderer()
    { 
        m_Device = MTL::CreateSystemDefaultDevice();
        if (!m_Device)
        {
            std::runtime_error("Failed to create ");
        }

    }

    Metal_Renderer::~Metal_Renderer()
    {
        m_Device->release();
    }

    void Metal_Renderer::Init()
    {
        std::cout << "Hello world!" << std::endl;
    }

    void Metal_Renderer::Init(GLFWwindow* pWindow)
    {
        m_WindowHandle = glfwGetCocoaWindow(pWindow);
        m_Layer = [CAMetalLayer layer];
        m_Layer.device = (__bridge id<MTLDevice>)m_Device;
        m_Layer.pixelFormat = MTLPixelFormatBGRA8Unorm;
        m_WindowHandle.contentView.layer = m_Layer;
        m_WindowHandle.contentView.wantsLayer = YES;
    }
}
