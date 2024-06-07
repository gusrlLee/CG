#pragma once 

#include "pch.h"
#include "Window.h"

namespace Lee 
{
    class Application 
    {
        public:
            Application();
            ~Application();

            virtual void Init();
            virtual void Run();
            virtual void Release();

        private:
    };
}