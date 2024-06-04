#pragma once 

namespace LE 
{
    class ShaderLibrary
    {
        public:
            virtual ~ShaderLibrary() = default;
            virtual void CreateNewFunction(std::string functionName) {}
    };
}