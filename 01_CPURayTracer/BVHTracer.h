#pragma once 

#include "glad/glad.h"

#include "Lee/Core.h"
#include "Scene.h"

class BVHTracer : public Lee::Application 
{
    public:
        void Init() override;
        void Run() override;
        void Release() override;

    private:
        Lee::Window* m_Window;
        Scene* m_Scene;
};