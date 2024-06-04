#pragma once 

#include "Renderer/CommandBuffer.h"

#include <Metal/Metal.hpp>
#include <Metal/Metal.h>

namespace LE 
{
    class MtCommandBuffer : public CommandBuffer
    {
        public:
            ~MtCommandBuffer() override;

        private:
            MTL::CommandBuffer* m_CommandBuffer;
    }

}