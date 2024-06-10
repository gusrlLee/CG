#pragma once 

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Mesh.h"
#include "Math.h"
#include "Ray.h"

#define MAX_STACK_SIZE 500

struct AABB3f {
    glm::vec3 min = glm::vec3(1e30f, 1e30f, 1e30f);
    glm::vec3 max = glm::vec3(-1e30f, -1e30f, -1e30f);

    void grow(glm::vec3 p) { min = fminf(min, p), max = fmaxf(max, p);}
	float Area()
	{
		float e[3];
		e[0] = max.x - min.x;
		e[1] = max.y - min.y;
		e[2] = max.z - min.z;

		return e[0] * e[1] + e[1] * e[2] + e[2] * e[0]; // return e.x * e.y + e.y * e.z + e.z * e.x; 
	}
};

struct BVHNode {
    AABB3f aabb;
    int leftFirst, triCount;
    bool IsLeaf() { return triCount > 0; }
};

class BVH 
{
    public: 
        BVH();
        ~BVH() = default;

        void Init(Mesh* mesh);
        void Release();

        void Traversal(Ray& ray);

    private:
        // for construction of BVH 
        void Construction(Mesh* mesh);
        void UpdateNodeBounds(Mesh* mesh, int nodeIdx);
        void Subdivide(Mesh* mesh, int nodeIdx);
        float EvaluateSAH(Triangle* triangleList, BVHNode& node, int axis, float pos);

        void Swap( const int a, const int b );

        void IntersectTriangle(Ray& ray, Triangle& tri);
        float IntersectAABB(Ray& ray, glm::vec3& bmin, glm::vec3& bmax);

        BVHNode* m_Nodes;
        int* m_TriangleIndexList;
        Mesh* m_MeshData;
        int m_UsedNodeCount;
        int m_RootIndex;
};