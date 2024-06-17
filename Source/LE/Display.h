#pragma once 
#include <iostream>
#include <string>

#include "Core.h"
#include <GLFW/glfw3.h>

namespace LE 
{
    namespace Display
    {
        extern GLFWwindow* g_Display;
        extern CA::MetalLayer* g_Layer;
        extern NS::Window* g_NativeDisplay; 
        extern CA::MetalDrawable* g_SwapChain;

        extern int g_DisplayWidth;
        extern int g_DisplayHeight;

        void Init();
        void Shutdown();

        bool IsShouldClose();
        void Update();

        int GetDisplayWidth();
        int GetDisplayHeight();

        void SwapBuffers();
    }
}