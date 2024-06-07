#pragma once 

#include "pch.h"
#include <GLFW/glfw3.h>

namespace Lee
{
    class Window
    {
        public:
            Window();
            ~Window();
            bool IsWindowShouldClose();
            GLFWwindow* GetNativeWindowPtr();
            int GetWindowWidth() { return m_Width; }
            int GetWindowHeight() { return m_Height; }

            void Update();

        private:
            int m_Width, m_Height;
            GLFWwindow* m_Window;
    };
}