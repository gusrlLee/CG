#include "Renderer.h"
#include "Utils/FileUtils.h"

#include "RenderRHI/GraphicsContextBridge.h"

namespace LE 
{
    Renderer::Renderer()
    {
        // m_pRHI = CreateRenderRHI_Metal();
        // if we use Metal API 
        m_GraphicsContext = CreateMetalGraphicsContext();
    }

    Renderer::~Renderer()
    {
        // delete m_pRHI;
        delete m_CommandQueue;
        delete m_Device;
        delete m_RenderPipeline;
    }

    void Renderer::Init()
    {
        // m_pRHI->Init();
    }
    
    void Renderer::Init(GLFWwindow* pWindow)
    {
        // m_pRHI->Init(pWindow);
        m_Device = m_GraphicsContext->CreateDevice();
        m_CommandQueue = m_Device->CreateCommandQueue();

        m_RenderPipeline = m_Device->CreateRenderPipeline(
            LoadShaderSourceCodeFromFile("../Shader/Metal/Triangle.metal"),
            "vertexShader",
            "fragmentShader"
        );
    }
}