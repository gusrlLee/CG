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
        // 1. Graphics API Setting 

        // 2. Window Setting 
        
        // 3. Load model asset

        // (option) construction of accelereation structure 

        // 4. Rendering System Setting

        // 5. Renderer init()

        // Rendering Feature 
        


    }

    void Application::Run()
    {
        while (!m_Window->IsWindowShouldClose()) 
        {
            m_Window->Display();
        }
    }
}