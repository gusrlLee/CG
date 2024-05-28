#pragma once 

#include "Renderer/RenderRHI.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#define GLFW_EXPOSE_NATIVE_COCOA
#include "GLFW/glfw3native.h"

#include "Metal/Metal.hpp"
#include "Metal/Metal.h"
#include "QuartzCore/CAMetalLayer.hpp"
#include "QuartzCore/CAMetalLayer.h"
#include "QuartzCore/QuartzCore.hpp"

namespace LE 
{
    class Metal_Renderer : public RenderRHI
    {
        public:
            Metal_Renderer();
            virtual ~Metal_Renderer() override;

            virtual void Init() override;
            virtual void Init(GLFWwindow* pWindow) override;

        private:
            MTL::Device* m_Device;
            GLFWwindow* m_Window;
            NSWindow* m_WindowHandle;
            CAMetalLayer* m_Layer;
    };
}
