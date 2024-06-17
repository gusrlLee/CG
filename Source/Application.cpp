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

}

void Application::Run()
{
    while (!LE::Display::IsShouldClose())
    {
        LE::Display::Update();

        LE::Renderer::BeginFrame();
        LE::Display::SwapBuffers(); // TODO: Change This function! 

        LE::Renderer::EndFrame();
    }
}

void Application::Release()
{
    LE::Shutdown();
}