#pragma once 
#include "Renderer/CommandQueue.h"
#include <Metal/Metal.hpp>
#include <Metal/Metal.h>

namespace LE 
{
    class MtCommandQueue : public CommandQueue
    {
        public:
            ~MtCommandQueue() override;
        
        private:
            MTL::CommandQueue* m_CommandQueue;
    };
}