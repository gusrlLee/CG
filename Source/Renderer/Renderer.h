#pragma once 
#include "Window.h"
#include "RHI.h"

#include <iostream>


namespace Lee 
{
    class Renderer 
    {
        public:
            static RHI::API GetAPI() { return RHI::GetAPI(); }
            
            Renderer() = default;
            ~Renderer() = default;

            void Init(Window* pWindow);
            void Release();

            void Drawable();
            void Draw();

        private:
            static RHI* s_RHI;
    };
}