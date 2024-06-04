#include "Window.h"

namespace Lee
{
    Window::Window()
    {
        m_Window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
        if (!m_Window)
        {
            glfwTerminate();
            std::runtime_error("Failed to create GLFW window. Check This!\n");
        }
    }

    Window::~Window()
    {
        glfwDestroyWindow(m_Window);
    }

    bool Window::IsWindowShouldClose()
    {   
        return glfwWindowShouldClose(m_Window);
    }

    void Window::Update()
    {
        glfwPollEvents();
    }
}