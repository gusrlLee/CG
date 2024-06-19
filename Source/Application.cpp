#include "Application.h"

Application::Application()
{
    LE::Init();
}

Application::~Application()
{
}

void Application::Init()
{
    // Load Primitive or Mesh Data for Rendering 
}

void Application::Run()
{
    while (!LE::Display::IsShouldClose())
    {
        // Renderer Begin Frame 
        LE::Renderer::BeginFrame();

        // Start of Path Tracer's Rendering 
        LE::Renderer::RenderQuad();

        // Renderer End Frame 
        LE::Renderer::EndFrame();

        // Display Update
        LE::Display::Update();
    }
}

void Application::Release()
{
    // Memory Delete 
    LE::Shutdown();
}