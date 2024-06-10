#include "BVH.h"
#include "Timer.h"

using namespace std;
void BVH::Swap( const int a, const int b )
{
    int t = m_TriangleIndexList[a]; 
    m_TriangleIndexList[a] = m_TriangleIndexList[b]; 
    m_TriangleIndexList[b] = t;
}

BVH::BVH()
{

}

void BVH::Init(Mesh* mesh)
{
    m_Nodes = new BVHNode[mesh->GetPrimitivesCount() * 2 - 1];
    m_TriangleIndexList = new int[mesh->GetPrimitivesCount()];
    m_MeshData = mesh;

    for (int i=0; i<mesh->GetPrimitivesCount(); i++) 
        m_TriangleIndexList[i] = i;

    Construction(mesh);
}

void BVH::Release()
{
    delete[] m_Nodes;
    delete[] m_TriangleIndexList;
}

void BVH::Construction(Mesh* mesh)
{
    m_RootIndex = 0;
    m_UsedNodeCount = 1;

    BVHNode& root = m_Nodes[m_RootIndex];
    root.leftFirst = 0; root.triCount = mesh->GetPrimitivesCount();

    UpdateNodeBounds(mesh, m_RootIndex);
    Subdivide(mesh, m_RootIndex);
}

void BVH::UpdateNodeBounds(Mesh* mesh, int nodeIdx)
{

    BVHNode& node = m_Nodes[nodeIdx];
    Triangle* triList = mesh->GetPrimitivesData();

    node.aabb.min = glm::vec3(1e30f);
    node.aabb.max = glm::vec3(-1e30f);
    
	for (int first = node.leftFirst, i = 0; i < node.triCount; i++)
	{
		int leafTriIdx = m_TriangleIndexList[first + i];
		Triangle& leafTri = triList[leafTriIdx];
		node.aabb.min = fminf( node.aabb.min, leafTri.v0 ),
		node.aabb.min = fminf( node.aabb.min, leafTri.v1 ),
		node.aabb.min = fminf( node.aabb.min, leafTri.v2 ),
		node.aabb.max = fmaxf( node.aabb.max, leafTri.v0 ),
		node.aabb.max = fmaxf( node.aabb.max, leafTri.v1 ),
		node.aabb.max = fmaxf( node.aabb.max, leafTri.v2 );
	}
}

void BVH::Subdivide(Mesh* mesh, int nodeIdx)
{
    BVHNode& node = m_Nodes[nodeIdx];
    Triangle* triangleList = mesh->GetPrimitivesData();

    int bestAxis = -1;
    int bestPos = 0;
    float bestCost = 1e30f;

    for (int axis = 0; axis < 3; axis++)
    {
        for (uint i = 0; i < node.triCount; i++)
        {
            Triangle& triangle = triangleList[node.leftFirst + i];
            float candidatePos = triangle.centroid[axis];
            float cost = EvaluateSAH(triangleList, node, axis, candidatePos);
            if (cost < bestCost)
            {
                bestPos = candidatePos;
                bestAxis = axis;
                bestCost = cost;
            }
        }
    }

    int axis = bestAxis;
    float splitPos = bestPos;
    glm::vec3 e = node.aabb.max - node.aabb.min;
    float parentArea = e.x * e.y + e.y * e.z + e.z * e.x;
    float parentCost = node.triCount * parentArea;
    if (bestCost >= parentCost) return;

    int i = node.leftFirst;
	int j = i + node.triCount - 1;
	while (i <= j)
	{
		if (triangleList[m_TriangleIndexList[i]].centroid[axis] < splitPos)
			i++;
		else
			Swap( m_TriangleIndexList[i], m_TriangleIndexList[j--] );
	}

    // abort split if one of the sides is empty
	int leftCount = i - node.leftFirst;
	if (leftCount == 0 || leftCount == node.triCount) return;
	// create child nodes
	int leftChildIdx = m_UsedNodeCount++;
	int rightChildIdx = m_UsedNodeCount++;
	m_Nodes[leftChildIdx].leftFirst = node.leftFirst;
	m_Nodes[leftChildIdx].triCount = leftCount;
	m_Nodes[rightChildIdx].leftFirst = i;
	m_Nodes[rightChildIdx].triCount = node.triCount - leftCount;

	node.leftFirst = leftChildIdx;
	node.triCount = 0;

	UpdateNodeBounds( mesh, leftChildIdx );
	UpdateNodeBounds( mesh, rightChildIdx );
	// recurse
	Subdivide( mesh, leftChildIdx );
	Subdivide( mesh, rightChildIdx );
}

float BVH::EvaluateSAH(Triangle* triangleList, BVHNode& node, int axis, float pos)
{
    // determine triangle counts and bounds for this split candidate
	AABB3f leftBox, rightBox;
	int leftCount = 0, rightCount = 0;
	for (uint i = 0; i < node.triCount; i++)
	{
		Triangle& triangle = triangleList[m_TriangleIndexList[node.leftFirst + i]];
		if (triangle.centroid[axis] < pos)
		{
			leftCount++;
			leftBox.grow( triangle.v0 );
			leftBox.grow( triangle.v1 );
			leftBox.grow( triangle.v2 );
		}
		else
		{
			rightCount++;
			rightBox.grow( triangle.v0 );
			rightBox.grow( triangle.v1 );
			rightBox.grow( triangle.v2 );
		}
	}
	float cost = leftCount * leftBox.Area() + rightCount * rightBox.Area();
	return cost > 0 ? cost : 1e30f;
}

void BVH::Traversal(Ray& ray)
{
    BVHNode* node = &m_Nodes[m_RootIndex];
    Triangle* triangleList = m_MeshData->GetPrimitivesData();
    BVHNode* stack[MAX_STACK_SIZE];
    int stackPtr = -1;

    // root setting 
    stack[0] = node;
    stackPtr++;

    while (1)
	{
		if (node->IsLeaf())
		{
			for (uint i = 0; i < node->triCount; i++)
				IntersectTriangle( ray, triangleList[m_TriangleIndexList[node->leftFirst + i]] );

			if (stackPtr == 0) 
                break; 
            else
                node = stack[--stackPtr];

			continue;
		}
		BVHNode* child1 = &m_Nodes[node->leftFirst];
		BVHNode* child2 = &m_Nodes[node->leftFirst + 1];

		float dist1 = IntersectAABB( ray, child1->aabb.min, child1->aabb.max );
		float dist2 = IntersectAABB( ray, child2->aabb.min, child2->aabb.max );

		if (dist1 > dist2) 
        { 
            std::swap( dist1, dist2 ); 
            std::swap( child1, child2 ); 
        }

		if (dist1 == 1e30f)
		{
			if (stackPtr == 0) 
                break; 
            else 
                node = stack[--stackPtr];
		}
		else
		{
			node = child1;
			if (dist2 != 1e30f) 
                stack[stackPtr++] = child2;
		}
	}
}

void BVH::IntersectTriangle(Ray& ray, Triangle& tri)
{
    glm::vec3 edge1 = tri.v1 - tri.v0;
    glm::vec3 edge2 = tri.v2 - tri.v0;
    glm::vec3 h = glm::cross(ray.d, edge2);
    float a = glm::dot(edge1, h);
	if (a > -0.0001f && a < 0.0001f) return; // ray parallel to triangle
    float f = 1 / a;
    glm::vec3 s = ray.o - tri.v0;
    float u = f * glm::dot(s, h);
   	if (u < 0 || u > 1) return; 
    glm::vec3 q = glm::cross(s, edge1);
    float v = f * glm::dot(ray.d, q);
   	if (v < 0 || u + v > 1) return; 
    float t = f * glm::dot(edge2, q);
    if (t > 0.00001f)
        ray.t = min(ray.t, t);
}


float BVH::IntersectAABB(Ray& ray, glm::vec3& bmin, glm::vec3& bmax)
{
	float tx1 = (bmin.x - ray.o.x) * ray.d.x, tx2 = (bmax.x - ray.o.x) * ray.d.x;
	float tmin = min( tx1, tx2 ), tmax = max( tx1, tx2 );
	float ty1 = (bmin.y - ray.o.y) * ray.d.y, ty2 = (bmax.y - ray.o.y) * ray.d.y;
	tmin = max( tmin, min( ty1, ty2 ) ), tmax = min( tmax, max( ty1, ty2 ) );
	float tz1 = (bmin.z - ray.o.z) * ray.d.z, tz2 = (bmax.z - ray.o.z) * ray.d.z;
	tmin = max( tmin, min( tz1, tz2 ) ), tmax = min( tmax, max( tz1, tz2 ) );
	if (tmax >= tmin && tmin < ray.t && tmax > 0) 
        return tmin; 
    else 
        return 1e30f;
}

