#include "Window.h"


namespace Lee 
{
    Window::Window(WindowData& windowData)
    {
        m_Width = windowData.Width;
        m_Height = windowData.Height;
        m_Title = windowData.Title;

        m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), NULL, NULL);
        if (!m_Window) 
        {
            glfwTerminate();
            std::runtime_error("Failed to create GLFW window!\n");
        }
    }

    Window::~Window()
    {
        glfwDestroyWindow(m_Window);
    }

    void Window::Update()
    {
        glfwPollEvents();
    }
}