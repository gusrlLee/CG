#pragma once 
#include "Core.h"
#include "Display.h"

namespace LE
{
    class Scene
    {
        public:
            Scene();
            ~Scene();
            
            void Update(unsigned char* pData);

        private:
            int m_Width, m_Height;
            MTL::Texture* m_Scene;
    };
}