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
        delete m_Buffer;
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

        m_Buffer = m_Device->CreateBuffer();
    }

    void Renderer::Draw()
    {
        // TODO:
        // 1. RenderPipeline 을 만드는 것 끝남.
        // 2. Device->CreateNewBuffer() implementation 
        // 3. save triangle vertex information --> Done! 
        // 4. So, RenderSystem is drawed by Renderer in this function. 
        // Make RenderSystem 
        // Renderer Initialization 
        // Draw Scene data 
    }
}