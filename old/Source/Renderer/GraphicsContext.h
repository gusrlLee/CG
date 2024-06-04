#pragma once 
#include "Device.h"

namespace LE 
{
    class GraphicsContext 
    {
        public:
            virtual ~GraphicsContext() = default;
            virtual Device* CreateDevice() {}
    };
}