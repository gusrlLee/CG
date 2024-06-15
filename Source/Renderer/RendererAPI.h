#pragma once 
#include <iostream>

namespace Lee
{
    class RendererAPI
    {
        public:
            enum class API
            {
                OpenGL = 0, Metal = 1, Vulkan = 2
            };

            static API GetAPI() { return s_API; }

        private:
            static API s_API;
    };
}