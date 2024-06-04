#include <iostream>
#include "Lee/Core.h"

class StarterPack : public Lee::Application
{
    public:
        void Init() override {
            m_Window = new Lee::Window();
        }

        void Run() override {
            while(!m_Window->IsWindowShouldClose())
            {
                m_Window->Update();
            }
        }

        void Release() override {
            delete m_Window;
        }

    private:
        Lee::Window* m_Window;
};


int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    StarterPack* app = new StarterPack;
    app->Init();
    app->Run();
    app->Release();

    delete app;

    glfwTerminate();
    return 0;
}