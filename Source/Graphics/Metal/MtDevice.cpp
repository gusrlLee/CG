#include "MtDevice.h"

namespace Lee
{
    MtDevice::MtDevice()
    {
        MTL::Device* m_pDevice = MTL::CreateSystemDefaultDevice();
        if (!m_pDevice)
        {
            std::runtime_error("Failed to create Metal Default Device!");
        }
    }

    MtDevice::~MtDevice()
    {
        m_pDevice->release();
    }



    void MtDevice::Init()
    {

    }
}