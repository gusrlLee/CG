#pragma once 

#include "Renderer/Buffer.h"
#include <Metal/Metal.hpp>
#include <Metal/Metal.h>

namespace LE 
{
    class MtBuffer : public Buffer
    {
        public:
            MtBuffer(MTL::Buffer* pBuffer);
            ~MtBuffer() override;

        private:
            MTL::Buffer* m_Buffer;

    };
}