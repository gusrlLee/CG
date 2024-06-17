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
        glfwTerminate();
    }

    void Application::Init()
    {
        WindowData windowData = {"Lee Engine", 1080, 720};
        m_Window = new Window(windowData);
        m_Renderer = new Renderer();
        m_Renderer->Init(m_Window);
    }

    void Application::Run()
    {
        while (!m_Window->IsShouldClose())
        {
            m_Renderer->Draw();
            m_Window->Update();

            
            // m_Window->Update()
            // m_Renderer->CommandPool()
            // m_Renderer->CreateCommandBuffer()
            // m_Renderer->BeginFrame()
            // m_BasicRenderSystem()->EncodingTo(commmandBuffer);
            // m_Renderer->EndFrame()
            // m_Renderer->swapchain();
        }
    }

    void Application::Release()
    {
        m_Renderer->Release();
        delete m_Window;
        delete m_Renderer;
    }
}