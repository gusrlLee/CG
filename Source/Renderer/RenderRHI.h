#pragma once 

#include <stdio.h>

namespace LE 
{
    class RenderRHI
    {
        public: 
            virtual ~RenderRHI() = default;
            virtual void Init() {};
    };
}