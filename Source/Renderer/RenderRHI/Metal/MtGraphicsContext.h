#pragma once 

#include "Renderer/GraphicsContext.h"

#include "MtDevice.h"

namespace LE 
{
    class MtGraphicsContext : public GraphicsContext
    {
        public:
            MtGraphicsContext() {}
            ~MtGraphicsContext() override {}
            Device* CreateDevice() override;
    };
}