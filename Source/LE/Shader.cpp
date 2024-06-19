#include "Shader.h"

namespace LE
{
    namespace Shader
    {
        MTL::RenderPipelineState* CreateRenderPipelineState(const char* shaderFilePath)
        {
            std::string shaderCode;
            std::ifstream shaderFile;
            shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

            try 
            {
                // open files
                shaderFile.open(shaderFilePath);
                std::stringstream shaderStream;
                // read file's buffer contents into streams
                shaderStream << shaderFile.rdbuf();
                // close file handlers
                shaderFile.close();

                shaderCode = shaderStream.str();
            }
            catch (std::ifstream::failure& e)
            {
                std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
            }

            NS::Error* pError = nullptr;
            MTL::Library* pLibrary = g_Device->newLibrary( NS::String::string(shaderCode.c_str(), NS::ASCIIStringEncoding), nullptr, &pError );
            std::cout << shaderCode << std::endl;
            
            if ( !pLibrary )
            {
                std::cout << "Failed to create library of [" << shaderFilePath << "] , Check this file!" << std::endl;
                std::cout << pError->localizedDescription()->utf8String() << std::endl;
                assert( false );
            }

            MTL::Function* pVertexFn = pLibrary->newFunction( NS::String::string("vertexMain", NS::ASCIIStringEncoding) );
            MTL::Function* pFragFn = pLibrary->newFunction( NS::String::string("fragmentMain", NS::ASCIIStringEncoding) );

            MTL::RenderPipelineDescriptor* pDesc = MTL::RenderPipelineDescriptor::alloc()->init();
            pDesc->setVertexFunction( pVertexFn );
            pDesc->setFragmentFunction( pFragFn );
            pDesc->colorAttachments()->object(0)->setPixelFormat( MTL::PixelFormat::PixelFormatBGRA8Unorm_sRGB );
            pDesc->setDepthAttachmentPixelFormat( MTL::PixelFormat::PixelFormatDepth16Unorm );

            MTL::RenderPipelineState* pPSO = g_Device->newRenderPipelineState( pDesc, &pError );
            if ( !pPSO )
            {
                std::cout << "Failed to Create RenderPipelineState [" << shaderFilePath << "] , Check this file!" << std::endl;
                assert( false );
            }

            pVertexFn->release();
            pFragFn->release();
            pDesc->release();
            return pPSO;
        }

        MTL::ComputePipelineState* CreateComputePipelineState(const char* shaderFilePath)
        {
            std::string shaderCode;
            std::ifstream shaderFile;
            shaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

            try 
            {
                // open files
                shaderFile.open(shaderFilePath);
                std::stringstream shaderStream;
                // read file's buffer contents into streams
                shaderStream << shaderFile.rdbuf();
                // close file handlers
                shaderFile.close();

                shaderCode = shaderStream.str();
            }
            catch (std::ifstream::failure& e)
            {
                std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
            }

            NS::Error* pError = nullptr;
            MTL::Library* pLibrary = g_Device->newLibrary( NS::String::string(shaderCode.c_str(), NS::ASCIIStringEncoding), nullptr, &pError );
            return nullptr;
        }
    }
}