#pragma once 

#include "Random.h"
#include "Primitives.h"

class Mesh 
{
    public:
        Mesh();
        ~Mesh() = default;

        void Release();
        void CreateRandomTriangles();
        void Set(const char* filePath);

        Triangle* GetPrimitivesData() { return m_Primitives; } 
        int GetPrimitivesCount() { return m_PrimitivesCount; }

    private:
        Triangle* m_Primitives;
        int m_PrimitivesCount;

};