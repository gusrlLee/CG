#pragma once 

#include "Platform/Window.h"
#include "Renderer/Renderer.h"

namespace LE 
{
    class Application 
    {
        public:
            Application();
            ~Application();

            void Run();

        private:
            void Init();

            Window* m_Window;
            Renderer* m_Renderer;
    };
}