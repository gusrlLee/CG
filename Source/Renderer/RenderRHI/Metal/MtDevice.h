#pragma once 

#include "Renderer/Device.h"

#include "Metal/Metal.hpp"
#include "Metal/Metal.h"

namespace LE 
{
    class MtDevice : public Device
    {
        public:
            MtDevice();
            ~MtDevice() override;

        private:
            MTL::Device* m_Device;
    };
}