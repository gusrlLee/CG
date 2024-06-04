#include "Application.h"

namespace Lee 
{
    Application::Application()
    {

    }

    Application::~Application()
    {
        
    }

    void Application::Init()
    {
        std::cout << "Init... " << std::endl;
    }
    
    void Application::Run()
    {
        std::cout << "Run... " << std::endl;
    }

    void Application::Release()
    {
        std::cout << "Release... " << std::endl;
    }
}