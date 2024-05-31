#pragma once 

#include "Math/Vertex.h"
#include <vector>

namespace LE 
{
    class MeshComponent : public Component
    {
        public:
            MeshComponent(); 
            ~MeshComponent() override;

        private:
            std::vector<Vertex> m_Vertices;
    };
}