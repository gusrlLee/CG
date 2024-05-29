#pragma once 
#include "CommandQueue.h"

namespace LE 
{
    class Device 
    {
        public:
            virtual ~Device() = default;
            virtual CommandQueue* CreateCommandQueue() {}
    };
}