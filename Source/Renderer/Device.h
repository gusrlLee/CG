#pragma once 

namespace LE 
{
    class Device 
    {
        public:
            virtual ~Device() = default;
            virtual CreateCommandQueue();
    };
}