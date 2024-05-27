#pragma once 

#include "../../RenderRHI.h"

namespace LE 
{
    class Metal_Renderer : public RenderRHI
    {
        public:
            Metal_Renderer();
            virtual ~Metal_Renderer() override;

            virtual void Init() override;

        private:

    };
}