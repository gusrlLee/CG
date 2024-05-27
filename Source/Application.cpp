#include "Application.h"

#include <iostream>

namespace LE 
{
    Application::Application()
    {
        m_Window = new Window();
        m_Renderer = new Renderer();
    }

    Application::~Application()
    {
        delete m_Window;
        delete m_Renderer;
    }

    void Application::Run()
    {
        m_Renderer->Init();

        while (!m_Window->IsWindowShouldClose()) 
        {
            m_Window->Display();
        }
    }
}