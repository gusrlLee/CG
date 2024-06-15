#pragma once 

#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

namespace Lee 
{
    struct WindowData 
    {
        std::string Title;
        int Width;
        int Height;
    };

    class Window 
    {
        public: 
            Window(WindowData& windowData);
            ~Window();

            void Update();

            int GetWidth() { return m_Width; }
            int GetHeight() { return m_Height; }

            GLFWwindow* GetGLFWwindowPtr() { return m_Window; }
            bool IsShouldClose() { return glfwWindowShouldClose(m_Window); }

        private:
            std::string m_Title;
            int m_Width, m_Height;
            GLFWwindow* m_Window;
    };
}