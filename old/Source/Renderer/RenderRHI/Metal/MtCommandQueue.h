#pragma once 

#include "Renderer/CommandQueue.h"

#include <Metal/Metal.hpp>
#include <Metal/Metal.h>

namespace LE 
{
    class MtCommandQueue : public CommandQueue
    {
        public:
            MtCommandQueue(MTL::CommandQueue* pCommandQueue);
            ~MtCommandQueue() override;
        
        private:
            MTL::CommandQueue* m_CommandQueue;
    };
}