#pragma once 
#include "Renderer/RHI.h"
#include "MtCommon.h"

namespace Lee
{
    class MtRHI : public RHI
    {
        public:
            MtRHI() = default;
            ~MtRHI() override {}
            void Init(GLFWwindow* pWindow) override;
            void Release() override;

            void Draw() override;
            void Drawable() override;

        private:
            MTL::Device* m_Device;
            CA::MetalLayer* m_MetalLayer;
            NS::Window* m_WindowDelegate;
            CA::MetalDrawable* m_SwapChain;
    };
}