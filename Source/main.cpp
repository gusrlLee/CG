#include <iostream>
#include "Application.h"

int main()
{
    Lee::Application* app = new Lee::Application();

    app->Init();
    app->Run();
    app->Release();

    delete app;
    return 0;
}