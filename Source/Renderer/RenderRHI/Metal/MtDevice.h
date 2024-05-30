#pragma once 

#include "Renderer/Device.h"
#include "Renderer/CommandQueue.h"
#include "Renderer/RenderPipeline.h"

#include "MtCommandQueue.h"
#include "MtRenderPipeline.h"

#include "Metal/Metal.hpp"
#include "Metal/Metal.h"

#include <iostream>
#include <string>

namespace LE 
{
    class MtDevice : public Device
    {
        public:
            MtDevice();
            ~MtDevice() override;

            CommandQueue* CreateCommandQueue() override;
            RenderPipeline* CreateRenderPipeline(std::string shaderSource, std::string vertexFunctionName, std::string fragmentFunctionName) override;

        private:
            MTL::Device* m_Device;
    };
}