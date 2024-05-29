#include "MtCommandQueue.h"

namespace LE
{
    MtCommandQueue::MtCommandQueue(MTL::CommandQueue* pCommandQueue)
    {
        m_CommandQueue = pCommandQueue;
    }

    MtCommandQueue::~MtCommandQueue()
    {

    }
}