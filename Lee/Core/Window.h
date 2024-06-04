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

            void Update();

        private:
            GLFWwindow* m_Window;
    };
}