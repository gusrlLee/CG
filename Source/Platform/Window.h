#pragma once 

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "Rendering Engine"

namespace LE 
{
    class Window
    {
        public:
            Window();
            ~Window();

            bool IsWindowShouldClose();
            void Display();
            GLFWwindow* GetWindowHandle();

        private:
            GLFWwindow* m_Window;
    };
}