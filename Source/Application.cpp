#include "Application.h"

#include <iostream>

namespace LE 
{
    Application::Application()
    {
        m_Window = new Window();
        m_Renderer = new Renderer();

        // Engine Component Initalization 
        Init();
    }

    Application::~Application()
    {
        delete m_Window;
        delete m_Renderer;
    }

    void Application::Init()
    {
        m_Renderer->Init(m_Window->GetWindowHandle());
    }

    void Application::Run()
    {
        while (!m_Window->IsWindowShouldClose()) 
        {
            m_Window->Display();
        }
    }
}