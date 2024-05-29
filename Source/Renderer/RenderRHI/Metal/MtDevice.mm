#include "MtDevice.h"

namespace LE 
{
    MtDevice::MtDevice()
    {
        m_Device = MTL::CreateSystemDefaultDevice();
    }

    MtDevice::~MtDevice()
    {
        m_Device->release();
    }

    CommandQueue* MtDevice::CreateCommandQueue()
    {
        CommandQueue* pCommandQueue = new MtCommandQueue(m_Device->newCommandQueue());
        return pCommandQueue;
    }

}