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
}