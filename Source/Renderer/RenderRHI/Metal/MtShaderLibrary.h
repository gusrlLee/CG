#pragma once 

#include "Renderer/ShaderLibrary.h"

#include "Metal/Metal.hpp"
#include "Metal/Metal.h"

#include "QuartzCore/CAMetalLayer.hpp"
#include "QuartzCore/CAMetalLayer.h"
#include "QuartzCore/QuartzCore.hpp"

namespace LE 
{
    class MtShaderLibrary : public ShaderLibrary
    {
        public:
            MtShaderLibrary(MTL::Library* pLibrary);
            ~MtShaderLibrary() override;

            void SetVertexShader(std::string functionName) override;
            void SetFragmentShader(std::string functionName) override;

            void GetVertexShader(std::string functionName) override;
            void GetFragmentShader(std::string functionName) override;

        private:
            MTL::Library* m_ShaderLibrary
            MTL::Function* m_VertexShader;
            MTL::Function* m_FragmentShader;
    };
}