#pragma once 
#include <GLFW/glfw3.h>
#include "Renderer/CommandQueue.h"

namespace Lee
{
    class RHI 
    {
        public:
            enum class API
            {
                OpenGL = 0, Metal = 1, Vulkan = 2, D3D12 = 3
            };

            static API GetAPI() { return s_API; }
            static RHI* Create();

            virtual ~RHI() = default;
            virtual void Init(GLFWwindow* pWindow) = 0;
            virtual void Release() = 0;

            virtual void Draw() = 0;
            virtual void Drawable() = 0;

            virtual CommandQueue* CreateCommandQueue() = 0;

        private:
            static API s_API;
    };
}