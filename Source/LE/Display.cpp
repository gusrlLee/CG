#include "Display.h"
#include "GLFWAdapter.h"

namespace LE
{
    namespace Display
    {
        GLFWwindow* g_Display = nullptr;
        CA::MetalLayer* g_Layer = nullptr;
        NS::Window* g_NativeDisplay = nullptr; 
        CA::MetalDrawable* g_SwapChain = nullptr;

        int g_DisplayWidth = 800;
        int g_DisplayHeight = 600;

        void Init()
        {
            // GLFW Init
            glfwInit();
            glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); 

            g_Display = glfwCreateWindow(g_DisplayWidth, g_DisplayHeight, "Rendering Engine", NULL, NULL);
            if(!g_Display)
            {
                std::runtime_error("Failed to create GLFWwindow!\n");
            }

            g_Layer = CA::MetalLayer::layer()->retain();
            g_Layer->setDevice(g_Device);
            g_Layer->setPixelFormat(MTL::PixelFormat::PixelFormatBGRA8Unorm);

            g_NativeDisplay = GetNSWindow(g_Display, g_Layer)->retain();
        }

        bool IsShouldClose()
        {
            return glfwWindowShouldClose(g_Display);
        }

        void Update()
        {
            glfwPollEvents();
        }

        void SwapBuffers()
        {
            g_SwapChain = g_Layer->nextDrawable();
        }

        CA::MetalDrawable* GetSwapChain()
        {
            return g_Layer->nextDrawable(); 
        }

        void Shutdown()
        {
            glfwDestroyWindow(g_Display);
            glfwTerminate();
        }

        int GetDisplayWidth()
        {
            return g_DisplayWidth;
        }

        int GetDisplayHeight()
        {
            return g_DisplayHeight;
        }

    }
}