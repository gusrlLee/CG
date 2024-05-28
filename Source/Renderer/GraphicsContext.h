#pragma once 
#include "Device.h"

namespace LE 
{
    class GraphicsContext 
    {
        public:
            virtual ~GraphicsContext() {}
            virtual Device* CreateDevice() {}
    };
}