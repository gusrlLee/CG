#include <iostream>
#include <glad/glad.h>
#define STB_IMAGE_IMPLEMENTATION
#include "BVHTracer.h"

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    BVHTracer* tracer = new BVHTracer();

    tracer->Init();
    tracer->Run();
    tracer->Release();

    delete tracer;    

    return 0;
}