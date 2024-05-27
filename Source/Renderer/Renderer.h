#pragma once 

#include "RenderRHI.h"

namespace LE 
{
    class Renderer
    {
        public:
           Renderer();
           ~Renderer();

           void Init();

        private:
            RenderRHI *m_pRHI;
    };
}