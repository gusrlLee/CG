#pragma once 

#include "Window.h"
#include <iostream>

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
            Window* m_Window;
    };
}