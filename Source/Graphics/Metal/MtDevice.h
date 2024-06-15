#pragma once 

#include "MtCommon.h"
#include "Renderer/Device.h"


namespace Lee
{
    class MtDevice : public Device
    {
        public:
            MtDevice();
            ~MtDevice() override;

            void Init() override;

        private:
            MTL::Device* m_pDevice;
    };
}