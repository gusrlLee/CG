#include "Application.h"

namespace Lee 
{
    Application::Application()
    {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    }

    Application::~Application()
    {
        
    }

    void Application::Init()
    {
        m_Width = WINDOW_WIDTH;
        m_Height = WINDOW_HEIGHT;

        m_Window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
        if (!m_Window)
        {
            glfwTerminate();
            std::runtime_error("Failed to create GLFW window. Check This!\n");
        }

        glfwSetWindowUserPointer(m_Window, this);
        glfwSetFramebufferSizeCallback(m_Window, FrameBufferSizeCallback);
        // glfwSetCursorPosCallback(m_Window, CursorPositionCallback);
        // glfwSetScrollCallback(m_Window, ScrollCallback);

        //Metal Device
        m_Device = MTL::CreateSystemDefaultDevice();

        //Metal Layer
        m_Layer = CA::MetalLayer::layer()->retain();
        m_Layer->setDevice(m_Device);
        m_Layer->setPixelFormat(MTL::PixelFormat::PixelFormatBGRA8Unorm);

        m_WindowHandler = GetNSWindow(m_Window, m_Layer)->retain();
        m_CommandQueue = m_Device->newCommandQueue()->retain();
    }
    
    void Application::Run()
    {
        CA::MetalDrawable* metalDrawable;

        while (!glfwWindowShouldClose(m_Window)) 
        {
            NS::AutoreleasePool* pool = NS::AutoreleasePool::alloc()->init();
            
            metalDrawable = m_Layer->nextDrawable();
            // Render System 
            MTL::CommandBuffer* commandBuffer = m_CommandQueue->commandBuffer();
            MTL::RenderPassDescriptor* renderPassDescriptor = MTL::RenderPassDescriptor::alloc()->init();
            MTL::RenderPassColorAttachmentDescriptor* colorAttachment = renderPassDescriptor->colorAttachments()->object(0);
            colorAttachment->setTexture(metalDrawable->texture());
            colorAttachment->setLoadAction(MTL::LoadActionClear);
            colorAttachment->setClearColor(MTL::ClearColor(0.75f, 0.25f, 0.125f, 1.0f));
            colorAttachment->setStoreAction(MTL::StoreActionStore);

            MTL::RenderCommandEncoder* renderCommandEncoder = commandBuffer->renderCommandEncoder(renderPassDescriptor);
            renderCommandEncoder->endEncoding();

            commandBuffer->presentDrawable(metalDrawable);
            commandBuffer->commit();
            commandBuffer->waitUntilCompleted();
           
            pool->release();
            
            glfwPollEvents();
        }
    }

    void Application::Release()
    {
        m_CommandQueue->release();
        m_Layer->release();
        m_WindowHandler->release();
        m_Device->release();
        glfwTerminate();
    }

    void Application::FrameBufferSizeCallback(GLFWwindow *window, int width, int height) 
    {
        Application* app = (Application*)glfwGetWindowUserPointer(window);
        app->ResizeFrameBuffer(width, height);
    }

    void Application::ResizeFrameBuffer(int width, int height) 
    {
        m_Layer->setDrawableSize(CGSizeMake(width, height));
    }
}