#include "Application.h"

#include "Renderer/Device.h"

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

        Device* device = Device::Create();
    }

    void Application::Run()
    {
        while (!m_Window->IsShouldClose())
        {
            m_Window->Update();
        }
    }

    void Application::Release()
    {
        delete m_Window;
    }
}