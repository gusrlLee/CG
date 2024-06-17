#pragma once 

#include "LE/LE.h"
#include <iostream>

class Application
{
    public:
        Application();
        ~Application();

        void Init();
        void Run();
        void Release();
};