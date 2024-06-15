#pragma once 
#include "RendererAPI.h"

namespace Lee 
{
    class Renderer 
    {
        public:
            static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

        private:
    };
}