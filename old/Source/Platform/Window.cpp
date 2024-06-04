#include "Window.h"

#include <iostream>

namespace LE 
{
    Window::Window()
    {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        m_Window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);

        if (!m_Window) {
            glfwTerminate();
            std::runtime_error("Failed to create window! Try again..\n");
        }
    }

    Window::~Window()
    {
        glfwTerminate();
    }

    bool Window::IsWindowShouldClose()
    {
        return glfwWindowShouldClose(m_Window);
    } 

    GLFWwindow* Window::GetWindowHandle()
    {
        return m_Window;
    }

    void Window::Display()
    {
        glfwPollEvents();
    }
}