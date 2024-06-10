#include "Mesh.h"

Mesh::Mesh()
{

}

void Mesh::Set(const char* filePath)
{

}

void Mesh::CreateRandomTriangles() 
{
    m_PrimitivesCount = 5000;
    m_Primitives = new Triangle[m_PrimitivesCount];

    for(int i=0; i<m_PrimitivesCount; i++)
    {
        // create random triangle
        glm::vec3 v0, v1, v2;
        glm::vec3 n0, n1, n2;

        glm::vec3 r0 = glm::vec3(RandomFloat(), RandomFloat(), RandomFloat());
        glm::vec3 r1 = glm::vec3(RandomFloat(), RandomFloat(), RandomFloat());
        glm::vec3 r2 = glm::vec3(RandomFloat(), RandomFloat(), RandomFloat());
        
        m_Primitives[i].v0 = glm::vec3( r0.x * 9 - 5, r0.y * 9 - 5, r0.z * 9 - 5 );
        m_Primitives[i].v1 = glm::vec3( r0.x + r1.x, r0.y + r1.y, r0.z + r1.z);
        m_Primitives[i].v2 = glm::vec3( r0.x + r2.x, r0.y + r2.y, r0.z + r2.z);

        m_Primitives[i].centroid.x = (m_Primitives[i].v0.x + m_Primitives[i].v1.x + m_Primitives[i].v2.x) * 0.3333f;
        m_Primitives[i].centroid.y = (m_Primitives[i].v0.y + m_Primitives[i].v1.y + m_Primitives[i].v2.y) * 0.3333f;
        m_Primitives[i].centroid.x = (m_Primitives[i].v0.z + m_Primitives[i].v1.z + m_Primitives[i].v2.z) * 0.3333f;
    }
}

void Mesh::Release()
{
    delete[] m_Primitives;
}