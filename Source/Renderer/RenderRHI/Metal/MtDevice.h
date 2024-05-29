#pragma once 

#include "Renderer/Device.h"
#include "Renderer/CommandQueue.h"

#include "MtCommandQueue.h"
#include "Metal/Metal.hpp"
#include "Metal/Metal.h"

namespace LE 
{
    class MtDevice : public Device
    {
        public:
            MtDevice();
            ~MtDevice() override;

            CommandQueue* CreateCommandQueue() override;

        private:
            MTL::Device* m_Device;
    };
}