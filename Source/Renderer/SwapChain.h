#pragma once 
#include "RendererAPI.h"

namespace Lee 
{
    class SwapChain
    {
        public: 
            static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
            static SwapChain* Create();
    };
}