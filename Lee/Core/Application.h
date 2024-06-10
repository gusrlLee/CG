#pragma once 

#include "pch.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <Foundation/Foundation.hpp>
#include <Metal/Metal.hpp>
#include <QuartzCore/CAMetalLayer.hpp>
#include <QuartzCore/QuartzCore.hpp>
#include <AppKit/AppKit.hpp>

#include "Graphics/Metal/WindowAdaptor.h"

namespace Lee 
{
    class Application 
    {
        public:
            Application();
            ~Application();

            void Init();
            void Run();
            void Release();

        private:
            // Window Handle Function 
            static void FrameBufferSizeCallback(GLFWwindow* window, int width, int height);
            void ResizeFrameBuffer(int width, int height);

            // static void CursorPositionCallback(GLFWwindow* window, double x, double y);
            // void UpdateMousePosition(double x, double y);

            // static void ScrollCallback(GLFWwindow* window, double xOffset, double yOffset);
            // void UpdateScrollPosition(double xOffset, double yOffset);

            void ProcessInput();

            int m_Width, m_Height;
            GLFWwindow* m_Window;

            NS::Window* m_WindowHandler;
            MTL::Device* m_Device;
            CA::MetalLayer* m_Layer;
            MTL::CommandQueue* m_CommandQueue;
            
    };
}