#pragma once 

#include <stdio.h>
#include "GLFW/glfw3.h"

namespace LE 
{
    class RenderRHI
    {
        public: 
            virtual ~RenderRHI() = default;
            virtual void Init() {}
            virtual void Init(GLFWwindow* pWindow) {}
    };
}