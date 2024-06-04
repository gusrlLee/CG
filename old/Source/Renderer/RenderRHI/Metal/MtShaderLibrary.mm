#include "MtShaderLibrary.h"

namespace LE 
{
    MtShaderLibrary::MtShaderLibrary(MTL::Library* pLibrary);
    {
        m_ShaderLibrary = pLibrary;
    }

    MtShaderLibrary::~MtShaderLibrary()
    {
        m_ShaderLibrary->release();
    }

    void MtShaderLibrary::CreateNewFunction(std::string functionName) 
    {
        
    }
}