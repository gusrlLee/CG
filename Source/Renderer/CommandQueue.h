#pragma once 

namespace Lee 
{
    class CommandQueue
    {
        virtual CommandBuffer* CreateCommandBuffer() = 0;
    };
}