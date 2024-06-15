#pragma once 
#include "RendererAPI.h"

namespace Lee 
{
    class Device 
    {
        public: 
            static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
            static Device* Create();

            virtual ~Device() = default;
            virtual void Init() = 0;
    };
}