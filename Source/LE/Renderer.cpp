#include "Renderer.h"

namespace LE
{
    namespace Renderer
    {
        NS::AutoreleasePool* pool = nullptr;
        MTL::CommandQueue* pCommandQueue = nullptr;
        MTL::CommandBuffer* pCommandBuffer = nullptr;
        MTL::RenderPipelineState* pRenderPSO = nullptr;
        MTL::Buffer* squareVertexBuffer = nullptr;
        Scene* grassTexture = nullptr;

        VertexData squareVertices[] {
            {{-0.5, -0.5,  0.5, 1.0f}, {0.0f, 0.0f}},
            {{-0.5,  0.5,  0.5, 1.0f}, {0.0f, 1.0f}},
            {{ 0.5,  0.5,  0.5, 1.0f}, {1.0f, 1.0f}},
            {{-0.5, -0.5,  0.5, 1.0f}, {0.0f, 0.0f}},
            {{ 0.5,  0.5,  0.5, 1.0f}, {1.0f, 1.0f}},
            {{ 0.5, -0.5,  0.5, 1.0f}, {1.0f, 0.0f}}
        };

        void Init()
        {
            squareVertexBuffer = g_Device->newBuffer(&squareVertices, sizeof(squareVertices), MTL::ResourceStorageModeShared);
            grassTexture = new Scene("../../Assets/mc_grass.jpeg");
            pCommandQueue = g_Device->newCommandQueue();
            pRenderPSO = Shader::CreateRenderPipelineState("./RenderQuad.metal");
        }

        void Shutdown()
        {
            delete grassTexture;
        }

        void BeginFrame()
        {
            pool = NS::AutoreleasePool::alloc()->init();
        }

        void RenderQuad()
        {
            pCommandBuffer = pCommandQueue->commandBuffer();
            CA::MetalDrawable* drawable = Display::GetSwapChain();

            MTL::RenderPassDescriptor* renderPassDescriptor = MTL::RenderPassDescriptor::alloc()->init();
            MTL::RenderPassColorAttachmentDescriptor* cd = renderPassDescriptor->colorAttachments()->object(0);
            cd->setTexture(drawable->texture());
            cd->setLoadAction(MTL::LoadActionClear);
            cd->setClearColor(MTL::ClearColor(41.0f/255.0f, 42.0f/255.0f, 48.0f/255.0f, 1.0));
            cd->setStoreAction(MTL::StoreActionStore);

            MTL::RenderCommandEncoder* renderCommandEncoder = pCommandBuffer->renderCommandEncoder(renderPassDescriptor);
            renderCommandEncoder->setRenderPipelineState(pRenderPSO);
            renderCommandEncoder->setVertexBuffer(squareVertexBuffer, 0, 0);
            MTL::PrimitiveType typeTriangle = MTL::PrimitiveTypeTriangle;
            NS::UInteger vertexStart = 0;
            NS::UInteger vertexCount = 6;
            renderCommandEncoder->setFragmentTexture(grassTexture->texture, 0);
            renderCommandEncoder->drawPrimitives(typeTriangle, vertexStart, vertexCount);

            renderCommandEncoder->endEncoding();

            pCommandBuffer->presentDrawable(drawable);
            pCommandBuffer->commit();
            pCommandBuffer->waitUntilCompleted();
        }

        void EndFrame()
        {
            pool->release();
        }
    }
}