#pragma once 

#include "GLFW/glfw3.h"

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

        private:
            RenderRHI *m_pRHI;
    };
}