#include <iostream>
#include "Application.h"

int main()
{
    Application* app = new Application();

    app->Init();
    app->Run();
    app->Release();

    delete app;
    return 0;
}