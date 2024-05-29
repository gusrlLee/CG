#pragma once 

#include "GLFW/glfw3.h"
#include "RenderSystem.h"

#include "GraphicsContext.h"
#include "Device.h"
#include "CommandQueue.h"

#include "RenderRHI.h"

namespace LE 
{
    class Renderer
    {
        public:
           Renderer();
           ~Renderer();

           void Init();
           void Init(GLFWwindow* pWindow);

           void Draw();

        private:
            // RenderRHI *m_pRHI;

            GraphicsContext* m_GraphicsContext;
            Device* m_Device;
            CommandQueue* m_CommandQueue;
    };
}