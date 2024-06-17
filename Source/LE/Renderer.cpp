#include "Renderer.h"

namespace LE
{
    namespace Renderer
    {
        NS::AutoreleasePool* pool = nullptr;

        VertexData squareVertices[] {
            {{-0.5, -0.5,  0.5, 1.0f}, {0.0f, 0.0f}},
            {{-0.5,  0.5,  0.5, 1.0f}, {0.0f, 1.0f}},
            {{ 0.5,  0.5,  0.5, 1.0f}, {1.0f, 1.0f}},
            {{-0.5, -0.5,  0.5, 1.0f}, {0.0f, 0.0f}},
            {{ 0.5,  0.5,  0.5, 1.0f}, {1.0f, 1.0f}},
            {{ 0.5, -0.5,  0.5, 1.0f}, {1.0f, 0.0f}}
        };
        MTL::Buffer* squareVertexBuffer;

        void Init()
        {
            squareVertexBuffer = g_Device->newBuffer(&squareVertices, sizeof(squareVertices), MTL::ResourceStorageModeShared);

        }

        void BeginFrame()
        {
            pool = NS::AutoreleasePool::alloc()->init();
        }

        void RenderQuad()
        {

        }

        void EndFrame()
        {
            pool->release();
        }
    }
}