#include "MtBuffer.h"

namespace LE 
{
    MtBuffer::MtBuffer(MTL::Buffer* pBuffer)
    {
        m_Buffer = pBuffer;
    }

    MtBuffer::~MtBuffer()
    {
        m_Buffer->release();
    }

}