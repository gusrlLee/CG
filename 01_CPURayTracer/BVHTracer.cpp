#include "BVHTracer.h"

void BVHTracer::Init()
{
    m_Window = new Lee::Window();

    // Initialization for using the OpenGL 
    glfwMakeContextCurrent(m_Window->GetNativeWindowPtr());

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        glfwTerminate();
        std::runtime_error("Failed to initialize GLAD\n");
        return;
    }    

    m_Scene = new Scene();
    m_Scene->Init();

    m_Mesh = new Mesh();
    m_Mesh->CreateRandomTriangles();

    m_BVH = new BVH();
    m_BVH->Init(m_Mesh);
}

void BVHTracer::Run()
{
    // Main Loop 
    while(!m_Window->IsWindowShouldClose())
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        m_Scene->Update();
        m_Scene->Draw();

        glfwSwapBuffers(m_Window->GetNativeWindowPtr());
        m_Window->Update();
    }
}

void BVHTracer::Release()
{
    m_Scene->Release();
    m_BVH->Release();
    m_Mesh->Release();

    delete m_Window;
    delete m_Mesh;
}